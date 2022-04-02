#include "global.h"
#include "battle.h"
#include "pokemon.h"
#include "graphics.h"
#include "sprite.h"
#include "util.h"
#include "pokemon_icon.h"
#include "battle_order.h"

struct SpeciesData getSpeciesData(struct BattlePokemon mon)
{
    return (struct SpeciesData){mon.species, mon.personality};
}

u8 GetBattlerWithLowestTicks()
{
    /*
    Returns the current battler to act, which is the
    battler with the smallest number of ticks.
    If tied, returns the first battler.
    */

    u8 i;
    u8 bestBattler = -1;
    u32 lowestTicks = 0xFFFFFFFF;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (!(gAbsentBattlerFlags & gBitTable[i]) && gBattlerTicks[i] < lowestTicks)
        {
            bestBattler = i;
            lowestTicks = gBattlerTicks[i];
        }
    }
    return bestBattler;
}

u32 GetBattlerSpeed(u8 battlerId)
{
    return 50;
}

u32 CalculateAddedTicks(u8 battlerId, u8 moveSpeed)
{
    return GetBattlerSpeed(battlerId) * moveSpeed;
}

void CalculateBattleOrder()
{
    u8 i;

    for (i = 0; i < gBattlersCount; i++)
        gBattlerTicks2[i] = gBattlerTicks[i];

    for (i = 0; i < MAX_BATTLERS_ORDER_COUNT; i++)
    {
        u8 battlerId = GetBattlerWithLowestTicks();
        gBattlerTurnOrder[i] = battlerId;
        gBattlerTicks[battlerId] += CalculateAddedTicks(battlerId, DEFAULT_MOVE_SPEED);
    }

    for (i = 0; i < gBattlersCount; i++)
        gBattlerTicks[i] = gBattlerTicks2[i];
}

// TODO: move this somewhere else
#define POKE_ICON_BASE_PAL_TAG 56000

static const struct OamData sMonBattleIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const u16 sSpriteImageSizes[3][4] =
{
    [ST_OAM_SQUARE] =
    {
        [SPRITE_SIZE(8x8)]   =  8 * 8  / 2,
        [SPRITE_SIZE(16x16)] = 16 * 16 / 2,
        [SPRITE_SIZE(32x32)] = 32 * 32 / 2,
        [SPRITE_SIZE(64x64)] = 64 * 64 / 2,
    },
    [ST_OAM_H_RECTANGLE] =
    {
        [SPRITE_SIZE(16x8)]  = 16 * 8  / 2,
        [SPRITE_SIZE(32x8)]  = 32 * 8  / 2,
        [SPRITE_SIZE(32x16)] = 32 * 16 / 2,
        [SPRITE_SIZE(64x32)] = 64 * 32 / 2,
    },
    [ST_OAM_V_RECTANGLE] =
    {
        [SPRITE_SIZE(8x16)]  =  8 * 16 / 2,
        [SPRITE_SIZE(8x32)]  =  8 * 32 / 2,
        [SPRITE_SIZE(16x32)] = 16 * 32 / 2,
        [SPRITE_SIZE(32x64)] = 32 * 64 / 2,
    },
};

void RedrawSprite(struct Sprite* sprite)
{
    RequestSpriteCopy(
        (u8 *)sprite->images,
        (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
        sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]
    );
}

void SpriteCallback_Redraw(struct Sprite* sprite)
{
    RedrawSprite(sprite);
}

const u8* GetMonBattleIconTiles(u16 species)
{
    return gMonBattleIconTable[species];
}

const u8 *GetMonBattleIconPtr(u16 species, u32 personality)
{
    return GetMonBattleIconTiles(GetIconSpecies(species, personality));
}

u8 CreateBattleMonTurnIcon(u16 species, u32 personality, s16 x, s16 y, u8 subpriority)
{
    struct OamData oam = sMonBattleIconOamData;
    void *image = (void*) GetMonIconPtr(species, personality);
    struct SpriteFrameImage images = {
        NULL,
        sSpriteImageSizes[oam.shape][oam.size],
    };
    u8 spriteId;
    struct Sprite *sprite;

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = TAG_NONE,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
        .oam = &oam,
        .anims = gDummySpriteAnimTable,
        .images = &images,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallback_Redraw,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    sprite = &gSprites[spriteId];
    sprite->images = (const struct SpriteFrameImage *)image;
}

u8 CreateBattleOrderMonIconSprite(u8 battlerId, s16 x, s16 y)
{
    struct SpeciesData speciesData = getSpeciesData(gBattleMons[battlerId]);

    u8 spriteId = CreateBattleMonTurnIcon(
        speciesData.species,
        speciesData.personality,
        x,
        y,
        4
    );

    return spriteId;
}

void UpdateBattleOrderMonIconSprite(u8 spriteId, u8 battlerId, struct SpeciesData oldSpeciesData)
{
    void *image;
    struct Sprite *sprite;
    struct SpeciesData speciesData = getSpeciesData(gBattleMons[battlerId]);

    if (
        speciesData.species != oldSpeciesData.species
        || speciesData.personality != oldSpeciesData.personality
    )
    {
        image = (void*) GetMonBattleIconPtr(
            speciesData.species,
            speciesData.personality
        );
        sprite = &gSprites[spriteId];
        sprite->images = (const struct SpriteFrameImage *)image;
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[speciesData.species]);
        RedrawSprite(sprite);
    }
}

void CreateAllBattleOrderMonIconSprites()
{
    u8 i, battlerId;
    s16 battleIcon_x, battleIcon_y;

    CalculateBattleOrder();

    LoadMonIconPalettes();
    for (i = 0; i < MAX_BATTLERS_ORDER_COUNT; i++)
    {
        battlerId = gBattlerTurnOrder[i];
        battleIcon_x = 230;
        battleIcon_y = 5 + 18 * i;
        gSpriteTurnOrder[i] = CreateBattleOrderMonIconSprite(battlerId, battleIcon_x, battleIcon_y);
        gSpeciesTurnOrder[i] = getSpeciesData(gBattleMons[battlerId]);
    }
}

void UpdateBattleOrderMonIconSprites()
{
    u8 i, battlerId;

    CalculateBattleOrder();

    for (i = 0; i < MAX_BATTLERS_ORDER_COUNT; i++)
    {
        battlerId = gBattlerTurnOrder[i];
        UpdateBattleOrderMonIconSprite(gSpriteTurnOrder[i], battlerId, gSpeciesTurnOrder[i]);
        gSpeciesTurnOrder[i] = getSpeciesData(gBattleMons[battlerId]);
    }
}
