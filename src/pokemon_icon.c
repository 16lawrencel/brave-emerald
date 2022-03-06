#include "global.h"
#include "graphics.h"
#include "mail.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "sprite.h"

#define INVALID_ICON_SPECIES SPECIES_OLD_UNOWN_J // Oddly specific, used when an icon should be a ?. Any of the 'old unown' would work

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const u8 *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);
static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite);

const u8 *const gMonBattleIconTable[] =
{
    [SPECIES_NONE] = gMonBattleIcon_Bulbasaur,
    [SPECIES_BULBASAUR] = gMonBattleIcon_Bulbasaur,
    [SPECIES_IVYSAUR] = gMonBattleIcon_Ivysaur,
    [SPECIES_VENUSAUR] = gMonBattleIcon_Venusaur,
    [SPECIES_CHARMANDER] = gMonBattleIcon_Charmander,
    [SPECIES_CHARMELEON] = gMonBattleIcon_Charmeleon,
    [SPECIES_CHARIZARD] = gMonBattleIcon_Charizard,
    [SPECIES_SQUIRTLE] = gMonBattleIcon_Squirtle,
    [SPECIES_WARTORTLE] = gMonBattleIcon_Wartortle,
    [SPECIES_BLASTOISE] = gMonBattleIcon_Blastoise,
    [SPECIES_CATERPIE] = gMonBattleIcon_Caterpie,
    [SPECIES_METAPOD] = gMonBattleIcon_Metapod,
    [SPECIES_BUTTERFREE] = gMonBattleIcon_Butterfree,
    [SPECIES_WEEDLE] = gMonBattleIcon_Weedle,
    [SPECIES_KAKUNA] = gMonBattleIcon_Kakuna,
    [SPECIES_BEEDRILL] = gMonBattleIcon_Beedrill,
    [SPECIES_PIDGEY] = gMonBattleIcon_Pidgey,
    [SPECIES_PIDGEOTTO] = gMonBattleIcon_Pidgeotto,
    [SPECIES_PIDGEOT] = gMonBattleIcon_Pidgeot,
    [SPECIES_RATTATA] = gMonBattleIcon_Rattata,
    [SPECIES_RATICATE] = gMonBattleIcon_Raticate,
    [SPECIES_SPEAROW] = gMonBattleIcon_Spearow,
    [SPECIES_FEAROW] = gMonBattleIcon_Fearow,
    [SPECIES_EKANS] = gMonBattleIcon_Ekans,
    [SPECIES_ARBOK] = gMonBattleIcon_Arbok,
    [SPECIES_PIKACHU] = gMonBattleIcon_Pikachu,
    [SPECIES_RAICHU] = gMonBattleIcon_Raichu,
    [SPECIES_SANDSHREW] = gMonBattleIcon_Sandshrew,
    [SPECIES_SANDSLASH] = gMonBattleIcon_Sandslash,
    [SPECIES_NIDORAN_F] = gMonBattleIcon_NidoranF,
    [SPECIES_NIDORINA] = gMonBattleIcon_Nidorina,
    [SPECIES_NIDOQUEEN] = gMonBattleIcon_Nidoqueen,
    [SPECIES_NIDORAN_M] = gMonBattleIcon_NidoranM,
    [SPECIES_NIDORINO] = gMonBattleIcon_Nidorino,
    [SPECIES_NIDOKING] = gMonBattleIcon_Nidoking,
    [SPECIES_CLEFAIRY] = gMonBattleIcon_Clefairy,
    [SPECIES_CLEFABLE] = gMonBattleIcon_Clefable,
    [SPECIES_VULPIX] = gMonBattleIcon_Vulpix,
    [SPECIES_NINETALES] = gMonBattleIcon_Ninetales,
    [SPECIES_JIGGLYPUFF] = gMonBattleIcon_Jigglypuff,
    [SPECIES_WIGGLYTUFF] = gMonBattleIcon_Wigglytuff,
    [SPECIES_ZUBAT] = gMonBattleIcon_Zubat,
    [SPECIES_GOLBAT] = gMonBattleIcon_Golbat,
    [SPECIES_ODDISH] = gMonBattleIcon_Oddish,
    [SPECIES_GLOOM] = gMonBattleIcon_Gloom,
    [SPECIES_VILEPLUME] = gMonBattleIcon_Vileplume,
    [SPECIES_PARAS] = gMonBattleIcon_Paras,
    [SPECIES_PARASECT] = gMonBattleIcon_Parasect,
    [SPECIES_VENONAT] = gMonBattleIcon_Venonat,
    [SPECIES_VENOMOTH] = gMonBattleIcon_Venomoth,
    [SPECIES_DIGLETT] = gMonBattleIcon_Diglett,
    [SPECIES_DUGTRIO] = gMonBattleIcon_Dugtrio,
    [SPECIES_MEOWTH] = gMonBattleIcon_Meowth,
    [SPECIES_PERSIAN] = gMonBattleIcon_Persian,
    [SPECIES_PSYDUCK] = gMonBattleIcon_Psyduck,
    [SPECIES_GOLDUCK] = gMonBattleIcon_Golduck,
    [SPECIES_MANKEY] = gMonBattleIcon_Mankey,
    [SPECIES_PRIMEAPE] = gMonBattleIcon_Primeape,
    [SPECIES_GROWLITHE] = gMonBattleIcon_Growlithe,
    [SPECIES_ARCANINE] = gMonBattleIcon_Arcanine,
    [SPECIES_POLIWAG] = gMonBattleIcon_Poliwag,
    [SPECIES_POLIWHIRL] = gMonBattleIcon_Poliwhirl,
    [SPECIES_POLIWRATH] = gMonBattleIcon_Poliwrath,
    [SPECIES_ABRA] = gMonBattleIcon_Abra,
    [SPECIES_KADABRA] = gMonBattleIcon_Kadabra,
    [SPECIES_ALAKAZAM] = gMonBattleIcon_Alakazam,
    [SPECIES_MACHOP] = gMonBattleIcon_Machop,
    [SPECIES_MACHOKE] = gMonBattleIcon_Machoke,
    [SPECIES_MACHAMP] = gMonBattleIcon_Machamp,
    [SPECIES_BELLSPROUT] = gMonBattleIcon_Bellsprout,
    [SPECIES_WEEPINBELL] = gMonBattleIcon_Weepinbell,
    [SPECIES_VICTREEBEL] = gMonBattleIcon_Victreebel,
    [SPECIES_TENTACOOL] = gMonBattleIcon_Tentacool,
    [SPECIES_TENTACRUEL] = gMonBattleIcon_Tentacruel,
    [SPECIES_GEODUDE] = gMonBattleIcon_Geodude,
    [SPECIES_GRAVELER] = gMonBattleIcon_Graveler,
    [SPECIES_GOLEM] = gMonBattleIcon_Golem,
    [SPECIES_PONYTA] = gMonBattleIcon_Ponyta,
    [SPECIES_RAPIDASH] = gMonBattleIcon_Rapidash,
    [SPECIES_SLOWPOKE] = gMonBattleIcon_Slowpoke,
    [SPECIES_SLOWBRO] = gMonBattleIcon_Slowbro,
    [SPECIES_MAGNEMITE] = gMonBattleIcon_Magnemite,
    [SPECIES_MAGNETON] = gMonBattleIcon_Magneton,
    [SPECIES_FARFETCHD] = gMonBattleIcon_Farfetchd,
    [SPECIES_DODUO] = gMonBattleIcon_Doduo,
    [SPECIES_DODRIO] = gMonBattleIcon_Dodrio,
    [SPECIES_SEEL] = gMonBattleIcon_Seel,
    [SPECIES_DEWGONG] = gMonBattleIcon_Dewgong,
    [SPECIES_GRIMER] = gMonBattleIcon_Grimer,
    [SPECIES_MUK] = gMonBattleIcon_Muk,
    [SPECIES_SHELLDER] = gMonBattleIcon_Shellder,
    [SPECIES_CLOYSTER] = gMonBattleIcon_Cloyster,
    [SPECIES_GASTLY] = gMonBattleIcon_Gastly,
    [SPECIES_HAUNTER] = gMonBattleIcon_Haunter,
    [SPECIES_GENGAR] = gMonBattleIcon_Gengar,
    [SPECIES_ONIX] = gMonBattleIcon_Onix,
    [SPECIES_DROWZEE] = gMonBattleIcon_Drowzee,
    [SPECIES_HYPNO] = gMonBattleIcon_Hypno,
    [SPECIES_KRABBY] = gMonBattleIcon_Krabby,
    [SPECIES_KINGLER] = gMonBattleIcon_Kingler,
    [SPECIES_VOLTORB] = gMonBattleIcon_Voltorb,
    [SPECIES_ELECTRODE] = gMonBattleIcon_Electrode,
    [SPECIES_EXEGGCUTE] = gMonBattleIcon_Exeggcute,
    [SPECIES_EXEGGUTOR] = gMonBattleIcon_Exeggutor,
    [SPECIES_CUBONE] = gMonBattleIcon_Cubone,
    [SPECIES_MAROWAK] = gMonBattleIcon_Marowak,
    [SPECIES_HITMONLEE] = gMonBattleIcon_Hitmonlee,
    [SPECIES_HITMONCHAN] = gMonBattleIcon_Hitmonchan,
    [SPECIES_LICKITUNG] = gMonBattleIcon_Lickitung,
    [SPECIES_KOFFING] = gMonBattleIcon_Koffing,
    [SPECIES_WEEZING] = gMonBattleIcon_Weezing,
    [SPECIES_RHYHORN] = gMonBattleIcon_Rhyhorn,
    [SPECIES_RHYDON] = gMonBattleIcon_Rhydon,
    [SPECIES_CHANSEY] = gMonBattleIcon_Chansey,
    [SPECIES_TANGELA] = gMonBattleIcon_Tangela,
    [SPECIES_KANGASKHAN] = gMonBattleIcon_Kangaskhan,
    [SPECIES_HORSEA] = gMonBattleIcon_Horsea,
    [SPECIES_SEADRA] = gMonBattleIcon_Seadra,
    [SPECIES_GOLDEEN] = gMonBattleIcon_Goldeen,
    [SPECIES_SEAKING] = gMonBattleIcon_Seaking,
    [SPECIES_STARYU] = gMonBattleIcon_Staryu,
    [SPECIES_STARMIE] = gMonBattleIcon_Starmie,
    [SPECIES_MR_MIME] = gMonBattleIcon_Mrmime,
    [SPECIES_SCYTHER] = gMonBattleIcon_Scyther,
    [SPECIES_JYNX] = gMonBattleIcon_Jynx,
    [SPECIES_ELECTABUZZ] = gMonBattleIcon_Electabuzz,
    [SPECIES_MAGMAR] = gMonBattleIcon_Magmar,
    [SPECIES_PINSIR] = gMonBattleIcon_Pinsir,
    [SPECIES_TAUROS] = gMonBattleIcon_Tauros,
    [SPECIES_MAGIKARP] = gMonBattleIcon_Magikarp,
    [SPECIES_GYARADOS] = gMonBattleIcon_Gyarados,
    [SPECIES_LAPRAS] = gMonBattleIcon_Lapras,
    [SPECIES_DITTO] = gMonBattleIcon_Ditto,
    [SPECIES_EEVEE] = gMonBattleIcon_Eevee,
    [SPECIES_VAPOREON] = gMonBattleIcon_Vaporeon,
    [SPECIES_JOLTEON] = gMonBattleIcon_Jolteon,
    [SPECIES_FLAREON] = gMonBattleIcon_Flareon,
    [SPECIES_PORYGON] = gMonBattleIcon_Porygon,
    [SPECIES_OMANYTE] = gMonBattleIcon_Omanyte,
    [SPECIES_OMASTAR] = gMonBattleIcon_Omastar,
    [SPECIES_KABUTO] = gMonBattleIcon_Kabuto,
    [SPECIES_KABUTOPS] = gMonBattleIcon_Kabutops,
    [SPECIES_AERODACTYL] = gMonBattleIcon_Aerodactyl,
    [SPECIES_SNORLAX] = gMonBattleIcon_Snorlax,
    [SPECIES_ARTICUNO] = gMonBattleIcon_Articuno,
    [SPECIES_ZAPDOS] = gMonBattleIcon_Zapdos,
    [SPECIES_MOLTRES] = gMonBattleIcon_Moltres,
    [SPECIES_DRATINI] = gMonBattleIcon_Dratini,
    [SPECIES_DRAGONAIR] = gMonBattleIcon_Dragonair,
    [SPECIES_DRAGONITE] = gMonBattleIcon_Dragonite,
    [SPECIES_MEWTWO] = gMonBattleIcon_Mewtwo,
    [SPECIES_MEW] = gMonBattleIcon_Mew,
    [SPECIES_CHIKORITA] = gMonBattleIcon_Chikorita,
    [SPECIES_BAYLEEF] = gMonBattleIcon_Bayleef,
    [SPECIES_MEGANIUM] = gMonBattleIcon_Meganium,
    [SPECIES_CYNDAQUIL] = gMonBattleIcon_Cyndaquil,
    [SPECIES_QUILAVA] = gMonBattleIcon_Quilava,
    [SPECIES_TYPHLOSION] = gMonBattleIcon_Typhlosion,
    [SPECIES_TOTODILE] = gMonBattleIcon_Totodile,
    [SPECIES_CROCONAW] = gMonBattleIcon_Croconaw,
    [SPECIES_FERALIGATR] = gMonBattleIcon_Feraligatr,
    [SPECIES_SENTRET] = gMonBattleIcon_Sentret,
    [SPECIES_FURRET] = gMonBattleIcon_Furret,
    [SPECIES_HOOTHOOT] = gMonBattleIcon_Hoothoot,
    [SPECIES_NOCTOWL] = gMonBattleIcon_Noctowl,
    [SPECIES_LEDYBA] = gMonBattleIcon_Ledyba,
    [SPECIES_LEDIAN] = gMonBattleIcon_Ledian,
    [SPECIES_SPINARAK] = gMonBattleIcon_Spinarak,
    [SPECIES_ARIADOS] = gMonBattleIcon_Ariados,
    [SPECIES_CROBAT] = gMonBattleIcon_Crobat,
    [SPECIES_CHINCHOU] = gMonBattleIcon_Chinchou,
    [SPECIES_LANTURN] = gMonBattleIcon_Lanturn,
    [SPECIES_PICHU] = gMonBattleIcon_Pichu,
    [SPECIES_CLEFFA] = gMonBattleIcon_Cleffa,
    [SPECIES_IGGLYBUFF] = gMonBattleIcon_Igglybuff,
    [SPECIES_TOGEPI] = gMonBattleIcon_Togepi,
    [SPECIES_TOGETIC] = gMonBattleIcon_Togetic,
    [SPECIES_NATU] = gMonBattleIcon_Natu,
    [SPECIES_XATU] = gMonBattleIcon_Xatu,
    [SPECIES_MAREEP] = gMonBattleIcon_Mareep,
    [SPECIES_FLAAFFY] = gMonBattleIcon_Flaaffy,
    [SPECIES_AMPHAROS] = gMonBattleIcon_Ampharos,
    [SPECIES_BELLOSSOM] = gMonBattleIcon_Bellossom,
    [SPECIES_MARILL] = gMonBattleIcon_Marill,
    [SPECIES_AZUMARILL] = gMonBattleIcon_Azumarill,
    [SPECIES_SUDOWOODO] = gMonBattleIcon_Sudowoodo,
    [SPECIES_POLITOED] = gMonBattleIcon_Politoed,
    [SPECIES_HOPPIP] = gMonBattleIcon_Hoppip,
    [SPECIES_SKIPLOOM] = gMonBattleIcon_Skiploom,
    [SPECIES_JUMPLUFF] = gMonBattleIcon_Jumpluff,
    [SPECIES_AIPOM] = gMonBattleIcon_Aipom,
    [SPECIES_SUNKERN] = gMonBattleIcon_Sunkern,
    [SPECIES_SUNFLORA] = gMonBattleIcon_Sunflora,
    [SPECIES_YANMA] = gMonBattleIcon_Yanma,
    [SPECIES_WOOPER] = gMonBattleIcon_Wooper,
    [SPECIES_QUAGSIRE] = gMonBattleIcon_Quagsire,
    [SPECIES_ESPEON] = gMonBattleIcon_Espeon,
    [SPECIES_UMBREON] = gMonBattleIcon_Umbreon,
    [SPECIES_MURKROW] = gMonBattleIcon_Murkrow,
    [SPECIES_SLOWKING] = gMonBattleIcon_Slowking,
    [SPECIES_MISDREAVUS] = gMonBattleIcon_Misdreavus,
    [SPECIES_UNOWN] = gMonBattleIcon_UnownA,
    [SPECIES_WOBBUFFET] = gMonBattleIcon_Wobbuffet,
    [SPECIES_GIRAFARIG] = gMonBattleIcon_Girafarig,
    [SPECIES_PINECO] = gMonBattleIcon_Pineco,
    [SPECIES_FORRETRESS] = gMonBattleIcon_Forretress,
    [SPECIES_DUNSPARCE] = gMonBattleIcon_Dunsparce,
    [SPECIES_GLIGAR] = gMonBattleIcon_Gligar,
    [SPECIES_STEELIX] = gMonBattleIcon_Steelix,
    [SPECIES_SNUBBULL] = gMonBattleIcon_Snubbull,
    [SPECIES_GRANBULL] = gMonBattleIcon_Granbull,
    [SPECIES_QWILFISH] = gMonBattleIcon_Qwilfish,
    [SPECIES_SCIZOR] = gMonBattleIcon_Scizor,
    [SPECIES_SHUCKLE] = gMonBattleIcon_Shuckle,
    [SPECIES_HERACROSS] = gMonBattleIcon_Heracross,
    [SPECIES_SNEASEL] = gMonBattleIcon_Sneasel,
    [SPECIES_TEDDIURSA] = gMonBattleIcon_Teddiursa,
    [SPECIES_URSARING] = gMonBattleIcon_Ursaring,
    [SPECIES_SLUGMA] = gMonBattleIcon_Slugma,
    [SPECIES_MAGCARGO] = gMonBattleIcon_Magcargo,
    [SPECIES_SWINUB] = gMonBattleIcon_Swinub,
    [SPECIES_PILOSWINE] = gMonBattleIcon_Piloswine,
    [SPECIES_CORSOLA] = gMonBattleIcon_Corsola,
    [SPECIES_REMORAID] = gMonBattleIcon_Remoraid,
    [SPECIES_OCTILLERY] = gMonBattleIcon_Octillery,
    [SPECIES_DELIBIRD] = gMonBattleIcon_Delibird,
    [SPECIES_MANTINE] = gMonBattleIcon_Mantine,
    [SPECIES_SKARMORY] = gMonBattleIcon_Skarmory,
    [SPECIES_HOUNDOUR] = gMonBattleIcon_Houndour,
    [SPECIES_HOUNDOOM] = gMonBattleIcon_Houndoom,
    [SPECIES_KINGDRA] = gMonBattleIcon_Kingdra,
    [SPECIES_PHANPY] = gMonBattleIcon_Phanpy,
    [SPECIES_DONPHAN] = gMonBattleIcon_Donphan,
    [SPECIES_PORYGON2] = gMonBattleIcon_Porygon2,
    [SPECIES_STANTLER] = gMonBattleIcon_Stantler,
    [SPECIES_SMEARGLE] = gMonBattleIcon_Smeargle,
    [SPECIES_TYROGUE] = gMonBattleIcon_Tyrogue,
    [SPECIES_HITMONTOP] = gMonBattleIcon_Hitmontop,
    [SPECIES_SMOOCHUM] = gMonBattleIcon_Smoochum,
    [SPECIES_ELEKID] = gMonBattleIcon_Elekid,
    [SPECIES_MAGBY] = gMonBattleIcon_Magby,
    [SPECIES_MILTANK] = gMonBattleIcon_Miltank,
    [SPECIES_BLISSEY] = gMonBattleIcon_Blissey,
    [SPECIES_RAIKOU] = gMonBattleIcon_Raikou,
    [SPECIES_ENTEI] = gMonBattleIcon_Entei,
    [SPECIES_SUICUNE] = gMonBattleIcon_Suicune,
    [SPECIES_LARVITAR] = gMonBattleIcon_Larvitar,
    [SPECIES_PUPITAR] = gMonBattleIcon_Pupitar,
    [SPECIES_TYRANITAR] = gMonBattleIcon_Tyranitar,
    [SPECIES_LUGIA] = gMonBattleIcon_Lugia,
    [SPECIES_HO_OH] = gMonBattleIcon_HoOh,
    [SPECIES_CELEBI] = gMonBattleIcon_Celebi,
    [SPECIES_OLD_UNOWN_B] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_C] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_D] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_E] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_F] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_G] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_H] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_I] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_J] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_K] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_L] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_M] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_N] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_O] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_P] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Q] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_R] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_S] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_T] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_U] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_V] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_W] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_X] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Y] = gMonBattleIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Z] = gMonBattleIcon_QuestionMark,
    [SPECIES_TREECKO] = gMonBattleIcon_Treecko,
    [SPECIES_GROVYLE] = gMonBattleIcon_Grovyle,
    [SPECIES_SCEPTILE] = gMonBattleIcon_Sceptile,
    [SPECIES_TORCHIC] = gMonBattleIcon_Torchic,
    [SPECIES_COMBUSKEN] = gMonBattleIcon_Combusken,
    [SPECIES_BLAZIKEN] = gMonBattleIcon_Blaziken,
    [SPECIES_MUDKIP] = gMonBattleIcon_Mudkip,
    [SPECIES_MARSHTOMP] = gMonBattleIcon_Marshtomp,
    [SPECIES_SWAMPERT] = gMonBattleIcon_Swampert,
    [SPECIES_POOCHYENA] = gMonBattleIcon_Poochyena,
    [SPECIES_MIGHTYENA] = gMonBattleIcon_Mightyena,
    [SPECIES_ZIGZAGOON] = gMonBattleIcon_Zigzagoon,
    [SPECIES_LINOONE] = gMonBattleIcon_Linoone,
    [SPECIES_WURMPLE] = gMonBattleIcon_Wurmple,
    [SPECIES_SILCOON] = gMonBattleIcon_Silcoon,
    [SPECIES_BEAUTIFLY] = gMonBattleIcon_Beautifly,
    [SPECIES_CASCOON] = gMonBattleIcon_Cascoon,
    [SPECIES_DUSTOX] = gMonBattleIcon_Dustox,
    [SPECIES_LOTAD] = gMonBattleIcon_Lotad,
    [SPECIES_LOMBRE] = gMonBattleIcon_Lombre,
    [SPECIES_LUDICOLO] = gMonBattleIcon_Ludicolo,
    [SPECIES_SEEDOT] = gMonBattleIcon_Seedot,
    [SPECIES_NUZLEAF] = gMonBattleIcon_Nuzleaf,
    [SPECIES_SHIFTRY] = gMonBattleIcon_Shiftry,
    [SPECIES_NINCADA] = gMonBattleIcon_Nincada,
    [SPECIES_NINJASK] = gMonBattleIcon_Ninjask,
    [SPECIES_SHEDINJA] = gMonBattleIcon_Shedinja,
    [SPECIES_TAILLOW] = gMonBattleIcon_Taillow,
    [SPECIES_SWELLOW] = gMonBattleIcon_Swellow,
    [SPECIES_SHROOMISH] = gMonBattleIcon_Shroomish,
    [SPECIES_BRELOOM] = gMonBattleIcon_Breloom,
    [SPECIES_SPINDA] = gMonBattleIcon_Spinda,
    [SPECIES_WINGULL] = gMonBattleIcon_Wingull,
    [SPECIES_PELIPPER] = gMonBattleIcon_Pelipper,
    [SPECIES_SURSKIT] = gMonBattleIcon_Surskit,
    [SPECIES_MASQUERAIN] = gMonBattleIcon_Masquerain,
    [SPECIES_WAILMER] = gMonBattleIcon_Wailmer,
    [SPECIES_WAILORD] = gMonBattleIcon_Wailord,
    [SPECIES_SKITTY] = gMonBattleIcon_Skitty,
    [SPECIES_DELCATTY] = gMonBattleIcon_Delcatty,
    [SPECIES_KECLEON] = gMonBattleIcon_Kecleon,
    [SPECIES_BALTOY] = gMonBattleIcon_Baltoy,
    [SPECIES_CLAYDOL] = gMonBattleIcon_Claydol,
    [SPECIES_NOSEPASS] = gMonBattleIcon_Nosepass,
    [SPECIES_TORKOAL] = gMonBattleIcon_Torkoal,
    [SPECIES_SABLEYE] = gMonBattleIcon_Sableye,
    [SPECIES_BARBOACH] = gMonBattleIcon_Barboach,
    [SPECIES_WHISCASH] = gMonBattleIcon_Whiscash,
    [SPECIES_LUVDISC] = gMonBattleIcon_Luvdisc,
    [SPECIES_CORPHISH] = gMonBattleIcon_Corphish,
    [SPECIES_CRAWDAUNT] = gMonBattleIcon_Crawdaunt,
    [SPECIES_FEEBAS] = gMonBattleIcon_Feebas,
    [SPECIES_MILOTIC] = gMonBattleIcon_Milotic,
    [SPECIES_CARVANHA] = gMonBattleIcon_Carvanha,
    [SPECIES_SHARPEDO] = gMonBattleIcon_Sharpedo,
    [SPECIES_TRAPINCH] = gMonBattleIcon_Trapinch,
    [SPECIES_VIBRAVA] = gMonBattleIcon_Vibrava,
    [SPECIES_FLYGON] = gMonBattleIcon_Flygon,
    [SPECIES_MAKUHITA] = gMonBattleIcon_Makuhita,
    [SPECIES_HARIYAMA] = gMonBattleIcon_Hariyama,
    [SPECIES_ELECTRIKE] = gMonBattleIcon_Electrike,
    [SPECIES_MANECTRIC] = gMonBattleIcon_Manectric,
    [SPECIES_NUMEL] = gMonBattleIcon_Numel,
    [SPECIES_CAMERUPT] = gMonBattleIcon_Camerupt,
    [SPECIES_SPHEAL] = gMonBattleIcon_Spheal,
    [SPECIES_SEALEO] = gMonBattleIcon_Sealeo,
    [SPECIES_WALREIN] = gMonBattleIcon_Walrein,
    [SPECIES_CACNEA] = gMonBattleIcon_Cacnea,
    [SPECIES_CACTURNE] = gMonBattleIcon_Cacturne,
    [SPECIES_SNORUNT] = gMonBattleIcon_Snorunt,
    [SPECIES_GLALIE] = gMonBattleIcon_Glalie,
    [SPECIES_LUNATONE] = gMonBattleIcon_Lunatone,
    [SPECIES_SOLROCK] = gMonBattleIcon_Solrock,
    [SPECIES_AZURILL] = gMonBattleIcon_Azurill,
    [SPECIES_SPOINK] = gMonBattleIcon_Spoink,
    [SPECIES_GRUMPIG] = gMonBattleIcon_Grumpig,
    [SPECIES_PLUSLE] = gMonBattleIcon_Plusle,
    [SPECIES_MINUN] = gMonBattleIcon_Minun,
    [SPECIES_MAWILE] = gMonBattleIcon_Mawile,
    [SPECIES_MEDITITE] = gMonBattleIcon_Meditite,
    [SPECIES_MEDICHAM] = gMonBattleIcon_Medicham,
    [SPECIES_SWABLU] = gMonBattleIcon_Swablu,
    [SPECIES_ALTARIA] = gMonBattleIcon_Altaria,
    [SPECIES_WYNAUT] = gMonBattleIcon_Wynaut,
    [SPECIES_DUSKULL] = gMonBattleIcon_Duskull,
    [SPECIES_DUSCLOPS] = gMonBattleIcon_Dusclops,
    [SPECIES_ROSELIA] = gMonBattleIcon_Roselia,
    [SPECIES_SLAKOTH] = gMonBattleIcon_Slakoth,
    [SPECIES_VIGOROTH] = gMonBattleIcon_Vigoroth,
    [SPECIES_SLAKING] = gMonBattleIcon_Slaking,
    [SPECIES_GULPIN] = gMonBattleIcon_Gulpin,
    [SPECIES_SWALOT] = gMonBattleIcon_Swalot,
    [SPECIES_TROPIUS] = gMonBattleIcon_Tropius,
    [SPECIES_WHISMUR] = gMonBattleIcon_Whismur,
    [SPECIES_LOUDRED] = gMonBattleIcon_Loudred,
    [SPECIES_EXPLOUD] = gMonBattleIcon_Exploud,
    [SPECIES_CLAMPERL] = gMonBattleIcon_Clamperl,
    [SPECIES_HUNTAIL] = gMonBattleIcon_Huntail,
    [SPECIES_GOREBYSS] = gMonBattleIcon_Gorebyss,
    [SPECIES_ABSOL] = gMonBattleIcon_Absol,
    [SPECIES_SHUPPET] = gMonBattleIcon_Shuppet,
    [SPECIES_BANETTE] = gMonBattleIcon_Banette,
    [SPECIES_SEVIPER] = gMonBattleIcon_Seviper,
    [SPECIES_ZANGOOSE] = gMonBattleIcon_Zangoose,
    [SPECIES_RELICANTH] = gMonBattleIcon_Relicanth,
    [SPECIES_ARON] = gMonBattleIcon_Aron,
    [SPECIES_LAIRON] = gMonBattleIcon_Lairon,
    [SPECIES_AGGRON] = gMonBattleIcon_Aggron,
    [SPECIES_CASTFORM] = gMonBattleIcon_Castform,
    [SPECIES_VOLBEAT] = gMonBattleIcon_Volbeat,
    [SPECIES_ILLUMISE] = gMonBattleIcon_Illumise,
    [SPECIES_LILEEP] = gMonBattleIcon_Lileep,
    [SPECIES_CRADILY] = gMonBattleIcon_Cradily,
    [SPECIES_ANORITH] = gMonBattleIcon_Anorith,
    [SPECIES_ARMALDO] = gMonBattleIcon_Armaldo,
    [SPECIES_RALTS] = gMonBattleIcon_Ralts,
    [SPECIES_KIRLIA] = gMonBattleIcon_Kirlia,
    [SPECIES_GARDEVOIR] = gMonBattleIcon_Gardevoir,
    [SPECIES_BAGON] = gMonBattleIcon_Bagon,
    [SPECIES_SHELGON] = gMonBattleIcon_Shelgon,
    [SPECIES_SALAMENCE] = gMonBattleIcon_Salamence,
    [SPECIES_BELDUM] = gMonBattleIcon_Beldum,
    [SPECIES_METANG] = gMonBattleIcon_Metang,
    [SPECIES_METAGROSS] = gMonBattleIcon_Metagross,
    [SPECIES_REGIROCK] = gMonBattleIcon_Regirock,
    [SPECIES_REGICE] = gMonBattleIcon_Regice,
    [SPECIES_REGISTEEL] = gMonBattleIcon_Registeel,
    [SPECIES_KYOGRE] = gMonBattleIcon_Kyogre,
    [SPECIES_GROUDON] = gMonBattleIcon_Groudon,
    [SPECIES_RAYQUAZA] = gMonBattleIcon_Rayquaza,
    [SPECIES_LATIAS] = gMonBattleIcon_Latias,
    [SPECIES_LATIOS] = gMonBattleIcon_Latios,
    [SPECIES_JIRACHI] = gMonBattleIcon_Jirachi,
    [SPECIES_DEOXYS] = gMonBattleIcon_Deoxys,
    [SPECIES_CHIMECHO] = gMonBattleIcon_Chimecho,
    [SPECIES_EGG] = gMonBattleIcon_Egg,
    [SPECIES_UNOWN_B] = gMonBattleIcon_UnownB,
    [SPECIES_UNOWN_C] = gMonBattleIcon_UnownC,
    [SPECIES_UNOWN_D] = gMonBattleIcon_UnownD,
    [SPECIES_UNOWN_E] = gMonBattleIcon_UnownE,
    [SPECIES_UNOWN_F] = gMonBattleIcon_UnownF,
    [SPECIES_UNOWN_G] = gMonBattleIcon_UnownG,
    [SPECIES_UNOWN_H] = gMonBattleIcon_UnownH,
    [SPECIES_UNOWN_I] = gMonBattleIcon_UnownI,
    [SPECIES_UNOWN_J] = gMonBattleIcon_UnownJ,
    [SPECIES_UNOWN_K] = gMonBattleIcon_UnownK,
    [SPECIES_UNOWN_L] = gMonBattleIcon_UnownL,
    [SPECIES_UNOWN_M] = gMonBattleIcon_UnownM,
    [SPECIES_UNOWN_N] = gMonBattleIcon_UnownN,
    [SPECIES_UNOWN_O] = gMonBattleIcon_UnownO,
    [SPECIES_UNOWN_P] = gMonBattleIcon_UnownP,
    [SPECIES_UNOWN_Q] = gMonBattleIcon_UnownQ,
    [SPECIES_UNOWN_R] = gMonBattleIcon_UnownR,
    [SPECIES_UNOWN_S] = gMonBattleIcon_UnownS,
    [SPECIES_UNOWN_T] = gMonBattleIcon_UnownT,
    [SPECIES_UNOWN_U] = gMonBattleIcon_UnownU,
    [SPECIES_UNOWN_V] = gMonBattleIcon_UnownV,
    [SPECIES_UNOWN_W] = gMonBattleIcon_UnownW,
    [SPECIES_UNOWN_X] = gMonBattleIcon_UnownX,
    [SPECIES_UNOWN_Y] = gMonBattleIcon_UnownY,
    [SPECIES_UNOWN_Z] = gMonBattleIcon_UnownZ,
    [SPECIES_UNOWN_EMARK] = gMonBattleIcon_UnownExclamationMark,
    [SPECIES_UNOWN_QMARK] = gMonBattleIcon_UnownQuestionMark,
};


const u8 *const gMonIconTable[] =
{
    [SPECIES_NONE] = gMonIcon_Bulbasaur,
    [SPECIES_BULBASAUR] = gMonIcon_Bulbasaur,
    [SPECIES_IVYSAUR] = gMonIcon_Ivysaur,
    [SPECIES_VENUSAUR] = gMonIcon_Venusaur,
    [SPECIES_CHARMANDER] = gMonIcon_Charmander,
    [SPECIES_CHARMELEON] = gMonIcon_Charmeleon,
    [SPECIES_CHARIZARD] = gMonIcon_Charizard,
    [SPECIES_SQUIRTLE] = gMonIcon_Squirtle,
    [SPECIES_WARTORTLE] = gMonIcon_Wartortle,
    [SPECIES_BLASTOISE] = gMonIcon_Blastoise,
    [SPECIES_CATERPIE] = gMonIcon_Caterpie,
    [SPECIES_METAPOD] = gMonIcon_Metapod,
    [SPECIES_BUTTERFREE] = gMonIcon_Butterfree,
    [SPECIES_WEEDLE] = gMonIcon_Weedle,
    [SPECIES_KAKUNA] = gMonIcon_Kakuna,
    [SPECIES_BEEDRILL] = gMonIcon_Beedrill,
    [SPECIES_PIDGEY] = gMonIcon_Pidgey,
    [SPECIES_PIDGEOTTO] = gMonIcon_Pidgeotto,
    [SPECIES_PIDGEOT] = gMonIcon_Pidgeot,
    [SPECIES_RATTATA] = gMonIcon_Rattata,
    [SPECIES_RATICATE] = gMonIcon_Raticate,
    [SPECIES_SPEAROW] = gMonIcon_Spearow,
    [SPECIES_FEAROW] = gMonIcon_Fearow,
    [SPECIES_EKANS] = gMonIcon_Ekans,
    [SPECIES_ARBOK] = gMonIcon_Arbok,
    [SPECIES_PIKACHU] = gMonIcon_Pikachu,
    [SPECIES_RAICHU] = gMonIcon_Raichu,
    [SPECIES_SANDSHREW] = gMonIcon_Sandshrew,
    [SPECIES_SANDSLASH] = gMonIcon_Sandslash,
    [SPECIES_NIDORAN_F] = gMonIcon_NidoranF,
    [SPECIES_NIDORINA] = gMonIcon_Nidorina,
    [SPECIES_NIDOQUEEN] = gMonIcon_Nidoqueen,
    [SPECIES_NIDORAN_M] = gMonIcon_NidoranM,
    [SPECIES_NIDORINO] = gMonIcon_Nidorino,
    [SPECIES_NIDOKING] = gMonIcon_Nidoking,
    [SPECIES_CLEFAIRY] = gMonIcon_Clefairy,
    [SPECIES_CLEFABLE] = gMonIcon_Clefable,
    [SPECIES_VULPIX] = gMonIcon_Vulpix,
    [SPECIES_NINETALES] = gMonIcon_Ninetales,
    [SPECIES_JIGGLYPUFF] = gMonIcon_Jigglypuff,
    [SPECIES_WIGGLYTUFF] = gMonIcon_Wigglytuff,
    [SPECIES_ZUBAT] = gMonIcon_Zubat,
    [SPECIES_GOLBAT] = gMonIcon_Golbat,
    [SPECIES_ODDISH] = gMonIcon_Oddish,
    [SPECIES_GLOOM] = gMonIcon_Gloom,
    [SPECIES_VILEPLUME] = gMonIcon_Vileplume,
    [SPECIES_PARAS] = gMonIcon_Paras,
    [SPECIES_PARASECT] = gMonIcon_Parasect,
    [SPECIES_VENONAT] = gMonIcon_Venonat,
    [SPECIES_VENOMOTH] = gMonIcon_Venomoth,
    [SPECIES_DIGLETT] = gMonIcon_Diglett,
    [SPECIES_DUGTRIO] = gMonIcon_Dugtrio,
    [SPECIES_MEOWTH] = gMonIcon_Meowth,
    [SPECIES_PERSIAN] = gMonIcon_Persian,
    [SPECIES_PSYDUCK] = gMonIcon_Psyduck,
    [SPECIES_GOLDUCK] = gMonIcon_Golduck,
    [SPECIES_MANKEY] = gMonIcon_Mankey,
    [SPECIES_PRIMEAPE] = gMonIcon_Primeape,
    [SPECIES_GROWLITHE] = gMonIcon_Growlithe,
    [SPECIES_ARCANINE] = gMonIcon_Arcanine,
    [SPECIES_POLIWAG] = gMonIcon_Poliwag,
    [SPECIES_POLIWHIRL] = gMonIcon_Poliwhirl,
    [SPECIES_POLIWRATH] = gMonIcon_Poliwrath,
    [SPECIES_ABRA] = gMonIcon_Abra,
    [SPECIES_KADABRA] = gMonIcon_Kadabra,
    [SPECIES_ALAKAZAM] = gMonIcon_Alakazam,
    [SPECIES_MACHOP] = gMonIcon_Machop,
    [SPECIES_MACHOKE] = gMonIcon_Machoke,
    [SPECIES_MACHAMP] = gMonIcon_Machamp,
    [SPECIES_BELLSPROUT] = gMonIcon_Bellsprout,
    [SPECIES_WEEPINBELL] = gMonIcon_Weepinbell,
    [SPECIES_VICTREEBEL] = gMonIcon_Victreebel,
    [SPECIES_TENTACOOL] = gMonIcon_Tentacool,
    [SPECIES_TENTACRUEL] = gMonIcon_Tentacruel,
    [SPECIES_GEODUDE] = gMonIcon_Geodude,
    [SPECIES_GRAVELER] = gMonIcon_Graveler,
    [SPECIES_GOLEM] = gMonIcon_Golem,
    [SPECIES_PONYTA] = gMonIcon_Ponyta,
    [SPECIES_RAPIDASH] = gMonIcon_Rapidash,
    [SPECIES_SLOWPOKE] = gMonIcon_Slowpoke,
    [SPECIES_SLOWBRO] = gMonIcon_Slowbro,
    [SPECIES_MAGNEMITE] = gMonIcon_Magnemite,
    [SPECIES_MAGNETON] = gMonIcon_Magneton,
    [SPECIES_FARFETCHD] = gMonIcon_Farfetchd,
    [SPECIES_DODUO] = gMonIcon_Doduo,
    [SPECIES_DODRIO] = gMonIcon_Dodrio,
    [SPECIES_SEEL] = gMonIcon_Seel,
    [SPECIES_DEWGONG] = gMonIcon_Dewgong,
    [SPECIES_GRIMER] = gMonIcon_Grimer,
    [SPECIES_MUK] = gMonIcon_Muk,
    [SPECIES_SHELLDER] = gMonIcon_Shellder,
    [SPECIES_CLOYSTER] = gMonIcon_Cloyster,
    [SPECIES_GASTLY] = gMonIcon_Gastly,
    [SPECIES_HAUNTER] = gMonIcon_Haunter,
    [SPECIES_GENGAR] = gMonIcon_Gengar,
    [SPECIES_ONIX] = gMonIcon_Onix,
    [SPECIES_DROWZEE] = gMonIcon_Drowzee,
    [SPECIES_HYPNO] = gMonIcon_Hypno,
    [SPECIES_KRABBY] = gMonIcon_Krabby,
    [SPECIES_KINGLER] = gMonIcon_Kingler,
    [SPECIES_VOLTORB] = gMonIcon_Voltorb,
    [SPECIES_ELECTRODE] = gMonIcon_Electrode,
    [SPECIES_EXEGGCUTE] = gMonIcon_Exeggcute,
    [SPECIES_EXEGGUTOR] = gMonIcon_Exeggutor,
    [SPECIES_CUBONE] = gMonIcon_Cubone,
    [SPECIES_MAROWAK] = gMonIcon_Marowak,
    [SPECIES_HITMONLEE] = gMonIcon_Hitmonlee,
    [SPECIES_HITMONCHAN] = gMonIcon_Hitmonchan,
    [SPECIES_LICKITUNG] = gMonIcon_Lickitung,
    [SPECIES_KOFFING] = gMonIcon_Koffing,
    [SPECIES_WEEZING] = gMonIcon_Weezing,
    [SPECIES_RHYHORN] = gMonIcon_Rhyhorn,
    [SPECIES_RHYDON] = gMonIcon_Rhydon,
    [SPECIES_CHANSEY] = gMonIcon_Chansey,
    [SPECIES_TANGELA] = gMonIcon_Tangela,
    [SPECIES_KANGASKHAN] = gMonIcon_Kangaskhan,
    [SPECIES_HORSEA] = gMonIcon_Horsea,
    [SPECIES_SEADRA] = gMonIcon_Seadra,
    [SPECIES_GOLDEEN] = gMonIcon_Goldeen,
    [SPECIES_SEAKING] = gMonIcon_Seaking,
    [SPECIES_STARYU] = gMonIcon_Staryu,
    [SPECIES_STARMIE] = gMonIcon_Starmie,
    [SPECIES_MR_MIME] = gMonIcon_Mrmime,
    [SPECIES_SCYTHER] = gMonIcon_Scyther,
    [SPECIES_JYNX] = gMonIcon_Jynx,
    [SPECIES_ELECTABUZZ] = gMonIcon_Electabuzz,
    [SPECIES_MAGMAR] = gMonIcon_Magmar,
    [SPECIES_PINSIR] = gMonIcon_Pinsir,
    [SPECIES_TAUROS] = gMonIcon_Tauros,
    [SPECIES_MAGIKARP] = gMonIcon_Magikarp,
    [SPECIES_GYARADOS] = gMonIcon_Gyarados,
    [SPECIES_LAPRAS] = gMonIcon_Lapras,
    [SPECIES_DITTO] = gMonIcon_Ditto,
    [SPECIES_EEVEE] = gMonIcon_Eevee,
    [SPECIES_VAPOREON] = gMonIcon_Vaporeon,
    [SPECIES_JOLTEON] = gMonIcon_Jolteon,
    [SPECIES_FLAREON] = gMonIcon_Flareon,
    [SPECIES_PORYGON] = gMonIcon_Porygon,
    [SPECIES_OMANYTE] = gMonIcon_Omanyte,
    [SPECIES_OMASTAR] = gMonIcon_Omastar,
    [SPECIES_KABUTO] = gMonIcon_Kabuto,
    [SPECIES_KABUTOPS] = gMonIcon_Kabutops,
    [SPECIES_AERODACTYL] = gMonIcon_Aerodactyl,
    [SPECIES_SNORLAX] = gMonIcon_Snorlax,
    [SPECIES_ARTICUNO] = gMonIcon_Articuno,
    [SPECIES_ZAPDOS] = gMonIcon_Zapdos,
    [SPECIES_MOLTRES] = gMonIcon_Moltres,
    [SPECIES_DRATINI] = gMonIcon_Dratini,
    [SPECIES_DRAGONAIR] = gMonIcon_Dragonair,
    [SPECIES_DRAGONITE] = gMonIcon_Dragonite,
    [SPECIES_MEWTWO] = gMonIcon_Mewtwo,
    [SPECIES_MEW] = gMonIcon_Mew,
    [SPECIES_CHIKORITA] = gMonIcon_Chikorita,
    [SPECIES_BAYLEEF] = gMonIcon_Bayleef,
    [SPECIES_MEGANIUM] = gMonIcon_Meganium,
    [SPECIES_CYNDAQUIL] = gMonIcon_Cyndaquil,
    [SPECIES_QUILAVA] = gMonIcon_Quilava,
    [SPECIES_TYPHLOSION] = gMonIcon_Typhlosion,
    [SPECIES_TOTODILE] = gMonIcon_Totodile,
    [SPECIES_CROCONAW] = gMonIcon_Croconaw,
    [SPECIES_FERALIGATR] = gMonIcon_Feraligatr,
    [SPECIES_SENTRET] = gMonIcon_Sentret,
    [SPECIES_FURRET] = gMonIcon_Furret,
    [SPECIES_HOOTHOOT] = gMonIcon_Hoothoot,
    [SPECIES_NOCTOWL] = gMonIcon_Noctowl,
    [SPECIES_LEDYBA] = gMonIcon_Ledyba,
    [SPECIES_LEDIAN] = gMonIcon_Ledian,
    [SPECIES_SPINARAK] = gMonIcon_Spinarak,
    [SPECIES_ARIADOS] = gMonIcon_Ariados,
    [SPECIES_CROBAT] = gMonIcon_Crobat,
    [SPECIES_CHINCHOU] = gMonIcon_Chinchou,
    [SPECIES_LANTURN] = gMonIcon_Lanturn,
    [SPECIES_PICHU] = gMonIcon_Pichu,
    [SPECIES_CLEFFA] = gMonIcon_Cleffa,
    [SPECIES_IGGLYBUFF] = gMonIcon_Igglybuff,
    [SPECIES_TOGEPI] = gMonIcon_Togepi,
    [SPECIES_TOGETIC] = gMonIcon_Togetic,
    [SPECIES_NATU] = gMonIcon_Natu,
    [SPECIES_XATU] = gMonIcon_Xatu,
    [SPECIES_MAREEP] = gMonIcon_Mareep,
    [SPECIES_FLAAFFY] = gMonIcon_Flaaffy,
    [SPECIES_AMPHAROS] = gMonIcon_Ampharos,
    [SPECIES_BELLOSSOM] = gMonIcon_Bellossom,
    [SPECIES_MARILL] = gMonIcon_Marill,
    [SPECIES_AZUMARILL] = gMonIcon_Azumarill,
    [SPECIES_SUDOWOODO] = gMonIcon_Sudowoodo,
    [SPECIES_POLITOED] = gMonIcon_Politoed,
    [SPECIES_HOPPIP] = gMonIcon_Hoppip,
    [SPECIES_SKIPLOOM] = gMonIcon_Skiploom,
    [SPECIES_JUMPLUFF] = gMonIcon_Jumpluff,
    [SPECIES_AIPOM] = gMonIcon_Aipom,
    [SPECIES_SUNKERN] = gMonIcon_Sunkern,
    [SPECIES_SUNFLORA] = gMonIcon_Sunflora,
    [SPECIES_YANMA] = gMonIcon_Yanma,
    [SPECIES_WOOPER] = gMonIcon_Wooper,
    [SPECIES_QUAGSIRE] = gMonIcon_Quagsire,
    [SPECIES_ESPEON] = gMonIcon_Espeon,
    [SPECIES_UMBREON] = gMonIcon_Umbreon,
    [SPECIES_MURKROW] = gMonIcon_Murkrow,
    [SPECIES_SLOWKING] = gMonIcon_Slowking,
    [SPECIES_MISDREAVUS] = gMonIcon_Misdreavus,
    [SPECIES_UNOWN] = gMonIcon_UnownA,
    [SPECIES_WOBBUFFET] = gMonIcon_Wobbuffet,
    [SPECIES_GIRAFARIG] = gMonIcon_Girafarig,
    [SPECIES_PINECO] = gMonIcon_Pineco,
    [SPECIES_FORRETRESS] = gMonIcon_Forretress,
    [SPECIES_DUNSPARCE] = gMonIcon_Dunsparce,
    [SPECIES_GLIGAR] = gMonIcon_Gligar,
    [SPECIES_STEELIX] = gMonIcon_Steelix,
    [SPECIES_SNUBBULL] = gMonIcon_Snubbull,
    [SPECIES_GRANBULL] = gMonIcon_Granbull,
    [SPECIES_QWILFISH] = gMonIcon_Qwilfish,
    [SPECIES_SCIZOR] = gMonIcon_Scizor,
    [SPECIES_SHUCKLE] = gMonIcon_Shuckle,
    [SPECIES_HERACROSS] = gMonIcon_Heracross,
    [SPECIES_SNEASEL] = gMonIcon_Sneasel,
    [SPECIES_TEDDIURSA] = gMonIcon_Teddiursa,
    [SPECIES_URSARING] = gMonIcon_Ursaring,
    [SPECIES_SLUGMA] = gMonIcon_Slugma,
    [SPECIES_MAGCARGO] = gMonIcon_Magcargo,
    [SPECIES_SWINUB] = gMonIcon_Swinub,
    [SPECIES_PILOSWINE] = gMonIcon_Piloswine,
    [SPECIES_CORSOLA] = gMonIcon_Corsola,
    [SPECIES_REMORAID] = gMonIcon_Remoraid,
    [SPECIES_OCTILLERY] = gMonIcon_Octillery,
    [SPECIES_DELIBIRD] = gMonIcon_Delibird,
    [SPECIES_MANTINE] = gMonIcon_Mantine,
    [SPECIES_SKARMORY] = gMonIcon_Skarmory,
    [SPECIES_HOUNDOUR] = gMonIcon_Houndour,
    [SPECIES_HOUNDOOM] = gMonIcon_Houndoom,
    [SPECIES_KINGDRA] = gMonIcon_Kingdra,
    [SPECIES_PHANPY] = gMonIcon_Phanpy,
    [SPECIES_DONPHAN] = gMonIcon_Donphan,
    [SPECIES_PORYGON2] = gMonIcon_Porygon2,
    [SPECIES_STANTLER] = gMonIcon_Stantler,
    [SPECIES_SMEARGLE] = gMonIcon_Smeargle,
    [SPECIES_TYROGUE] = gMonIcon_Tyrogue,
    [SPECIES_HITMONTOP] = gMonIcon_Hitmontop,
    [SPECIES_SMOOCHUM] = gMonIcon_Smoochum,
    [SPECIES_ELEKID] = gMonIcon_Elekid,
    [SPECIES_MAGBY] = gMonIcon_Magby,
    [SPECIES_MILTANK] = gMonIcon_Miltank,
    [SPECIES_BLISSEY] = gMonIcon_Blissey,
    [SPECIES_RAIKOU] = gMonIcon_Raikou,
    [SPECIES_ENTEI] = gMonIcon_Entei,
    [SPECIES_SUICUNE] = gMonIcon_Suicune,
    [SPECIES_LARVITAR] = gMonIcon_Larvitar,
    [SPECIES_PUPITAR] = gMonIcon_Pupitar,
    [SPECIES_TYRANITAR] = gMonIcon_Tyranitar,
    [SPECIES_LUGIA] = gMonIcon_Lugia,
    [SPECIES_HO_OH] = gMonIcon_HoOh,
    [SPECIES_CELEBI] = gMonIcon_Celebi,
    [SPECIES_OLD_UNOWN_B] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_C] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_D] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_E] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_F] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_G] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_H] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_I] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_J] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_K] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_L] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_M] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_N] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_O] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_P] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Q] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_R] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_S] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_T] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_U] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_V] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_W] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_X] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Y] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Z] = gMonIcon_QuestionMark,
    [SPECIES_TREECKO] = gMonIcon_Treecko,
    [SPECIES_GROVYLE] = gMonIcon_Grovyle,
    [SPECIES_SCEPTILE] = gMonIcon_Sceptile,
    [SPECIES_TORCHIC] = gMonIcon_Torchic,
    [SPECIES_COMBUSKEN] = gMonIcon_Combusken,
    [SPECIES_BLAZIKEN] = gMonIcon_Blaziken,
    [SPECIES_MUDKIP] = gMonIcon_Mudkip,
    [SPECIES_MARSHTOMP] = gMonIcon_Marshtomp,
    [SPECIES_SWAMPERT] = gMonIcon_Swampert,
    [SPECIES_POOCHYENA] = gMonIcon_Poochyena,
    [SPECIES_MIGHTYENA] = gMonIcon_Mightyena,
    [SPECIES_ZIGZAGOON] = gMonIcon_Zigzagoon,
    [SPECIES_LINOONE] = gMonIcon_Linoone,
    [SPECIES_WURMPLE] = gMonIcon_Wurmple,
    [SPECIES_SILCOON] = gMonIcon_Silcoon,
    [SPECIES_BEAUTIFLY] = gMonIcon_Beautifly,
    [SPECIES_CASCOON] = gMonIcon_Cascoon,
    [SPECIES_DUSTOX] = gMonIcon_Dustox,
    [SPECIES_LOTAD] = gMonIcon_Lotad,
    [SPECIES_LOMBRE] = gMonIcon_Lombre,
    [SPECIES_LUDICOLO] = gMonIcon_Ludicolo,
    [SPECIES_SEEDOT] = gMonIcon_Seedot,
    [SPECIES_NUZLEAF] = gMonIcon_Nuzleaf,
    [SPECIES_SHIFTRY] = gMonIcon_Shiftry,
    [SPECIES_NINCADA] = gMonIcon_Nincada,
    [SPECIES_NINJASK] = gMonIcon_Ninjask,
    [SPECIES_SHEDINJA] = gMonIcon_Shedinja,
    [SPECIES_TAILLOW] = gMonIcon_Taillow,
    [SPECIES_SWELLOW] = gMonIcon_Swellow,
    [SPECIES_SHROOMISH] = gMonIcon_Shroomish,
    [SPECIES_BRELOOM] = gMonIcon_Breloom,
    [SPECIES_SPINDA] = gMonIcon_Spinda,
    [SPECIES_WINGULL] = gMonIcon_Wingull,
    [SPECIES_PELIPPER] = gMonIcon_Pelipper,
    [SPECIES_SURSKIT] = gMonIcon_Surskit,
    [SPECIES_MASQUERAIN] = gMonIcon_Masquerain,
    [SPECIES_WAILMER] = gMonIcon_Wailmer,
    [SPECIES_WAILORD] = gMonIcon_Wailord,
    [SPECIES_SKITTY] = gMonIcon_Skitty,
    [SPECIES_DELCATTY] = gMonIcon_Delcatty,
    [SPECIES_KECLEON] = gMonIcon_Kecleon,
    [SPECIES_BALTOY] = gMonIcon_Baltoy,
    [SPECIES_CLAYDOL] = gMonIcon_Claydol,
    [SPECIES_NOSEPASS] = gMonIcon_Nosepass,
    [SPECIES_TORKOAL] = gMonIcon_Torkoal,
    [SPECIES_SABLEYE] = gMonIcon_Sableye,
    [SPECIES_BARBOACH] = gMonIcon_Barboach,
    [SPECIES_WHISCASH] = gMonIcon_Whiscash,
    [SPECIES_LUVDISC] = gMonIcon_Luvdisc,
    [SPECIES_CORPHISH] = gMonIcon_Corphish,
    [SPECIES_CRAWDAUNT] = gMonIcon_Crawdaunt,
    [SPECIES_FEEBAS] = gMonIcon_Feebas,
    [SPECIES_MILOTIC] = gMonIcon_Milotic,
    [SPECIES_CARVANHA] = gMonIcon_Carvanha,
    [SPECIES_SHARPEDO] = gMonIcon_Sharpedo,
    [SPECIES_TRAPINCH] = gMonIcon_Trapinch,
    [SPECIES_VIBRAVA] = gMonIcon_Vibrava,
    [SPECIES_FLYGON] = gMonIcon_Flygon,
    [SPECIES_MAKUHITA] = gMonIcon_Makuhita,
    [SPECIES_HARIYAMA] = gMonIcon_Hariyama,
    [SPECIES_ELECTRIKE] = gMonIcon_Electrike,
    [SPECIES_MANECTRIC] = gMonIcon_Manectric,
    [SPECIES_NUMEL] = gMonIcon_Numel,
    [SPECIES_CAMERUPT] = gMonIcon_Camerupt,
    [SPECIES_SPHEAL] = gMonIcon_Spheal,
    [SPECIES_SEALEO] = gMonIcon_Sealeo,
    [SPECIES_WALREIN] = gMonIcon_Walrein,
    [SPECIES_CACNEA] = gMonIcon_Cacnea,
    [SPECIES_CACTURNE] = gMonIcon_Cacturne,
    [SPECIES_SNORUNT] = gMonIcon_Snorunt,
    [SPECIES_GLALIE] = gMonIcon_Glalie,
    [SPECIES_LUNATONE] = gMonIcon_Lunatone,
    [SPECIES_SOLROCK] = gMonIcon_Solrock,
    [SPECIES_AZURILL] = gMonIcon_Azurill,
    [SPECIES_SPOINK] = gMonIcon_Spoink,
    [SPECIES_GRUMPIG] = gMonIcon_Grumpig,
    [SPECIES_PLUSLE] = gMonIcon_Plusle,
    [SPECIES_MINUN] = gMonIcon_Minun,
    [SPECIES_MAWILE] = gMonIcon_Mawile,
    [SPECIES_MEDITITE] = gMonIcon_Meditite,
    [SPECIES_MEDICHAM] = gMonIcon_Medicham,
    [SPECIES_SWABLU] = gMonIcon_Swablu,
    [SPECIES_ALTARIA] = gMonIcon_Altaria,
    [SPECIES_WYNAUT] = gMonIcon_Wynaut,
    [SPECIES_DUSKULL] = gMonIcon_Duskull,
    [SPECIES_DUSCLOPS] = gMonIcon_Dusclops,
    [SPECIES_ROSELIA] = gMonIcon_Roselia,
    [SPECIES_SLAKOTH] = gMonIcon_Slakoth,
    [SPECIES_VIGOROTH] = gMonIcon_Vigoroth,
    [SPECIES_SLAKING] = gMonIcon_Slaking,
    [SPECIES_GULPIN] = gMonIcon_Gulpin,
    [SPECIES_SWALOT] = gMonIcon_Swalot,
    [SPECIES_TROPIUS] = gMonIcon_Tropius,
    [SPECIES_WHISMUR] = gMonIcon_Whismur,
    [SPECIES_LOUDRED] = gMonIcon_Loudred,
    [SPECIES_EXPLOUD] = gMonIcon_Exploud,
    [SPECIES_CLAMPERL] = gMonIcon_Clamperl,
    [SPECIES_HUNTAIL] = gMonIcon_Huntail,
    [SPECIES_GOREBYSS] = gMonIcon_Gorebyss,
    [SPECIES_ABSOL] = gMonIcon_Absol,
    [SPECIES_SHUPPET] = gMonIcon_Shuppet,
    [SPECIES_BANETTE] = gMonIcon_Banette,
    [SPECIES_SEVIPER] = gMonIcon_Seviper,
    [SPECIES_ZANGOOSE] = gMonIcon_Zangoose,
    [SPECIES_RELICANTH] = gMonIcon_Relicanth,
    [SPECIES_ARON] = gMonIcon_Aron,
    [SPECIES_LAIRON] = gMonIcon_Lairon,
    [SPECIES_AGGRON] = gMonIcon_Aggron,
    [SPECIES_CASTFORM] = gMonIcon_Castform,
    [SPECIES_VOLBEAT] = gMonIcon_Volbeat,
    [SPECIES_ILLUMISE] = gMonIcon_Illumise,
    [SPECIES_LILEEP] = gMonIcon_Lileep,
    [SPECIES_CRADILY] = gMonIcon_Cradily,
    [SPECIES_ANORITH] = gMonIcon_Anorith,
    [SPECIES_ARMALDO] = gMonIcon_Armaldo,
    [SPECIES_RALTS] = gMonIcon_Ralts,
    [SPECIES_KIRLIA] = gMonIcon_Kirlia,
    [SPECIES_GARDEVOIR] = gMonIcon_Gardevoir,
    [SPECIES_BAGON] = gMonIcon_Bagon,
    [SPECIES_SHELGON] = gMonIcon_Shelgon,
    [SPECIES_SALAMENCE] = gMonIcon_Salamence,
    [SPECIES_BELDUM] = gMonIcon_Beldum,
    [SPECIES_METANG] = gMonIcon_Metang,
    [SPECIES_METAGROSS] = gMonIcon_Metagross,
    [SPECIES_REGIROCK] = gMonIcon_Regirock,
    [SPECIES_REGICE] = gMonIcon_Regice,
    [SPECIES_REGISTEEL] = gMonIcon_Registeel,
    [SPECIES_KYOGRE] = gMonIcon_Kyogre,
    [SPECIES_GROUDON] = gMonIcon_Groudon,
    [SPECIES_RAYQUAZA] = gMonIcon_Rayquaza,
    [SPECIES_LATIAS] = gMonIcon_Latias,
    [SPECIES_LATIOS] = gMonIcon_Latios,
    [SPECIES_JIRACHI] = gMonIcon_Jirachi,
    [SPECIES_DEOXYS] = gMonIcon_Deoxys,
    [SPECIES_CHIMECHO] = gMonIcon_Chimecho,
    [SPECIES_EGG] = gMonIcon_Egg,
    [SPECIES_UNOWN_B] = gMonIcon_UnownB,
    [SPECIES_UNOWN_C] = gMonIcon_UnownC,
    [SPECIES_UNOWN_D] = gMonIcon_UnownD,
    [SPECIES_UNOWN_E] = gMonIcon_UnownE,
    [SPECIES_UNOWN_F] = gMonIcon_UnownF,
    [SPECIES_UNOWN_G] = gMonIcon_UnownG,
    [SPECIES_UNOWN_H] = gMonIcon_UnownH,
    [SPECIES_UNOWN_I] = gMonIcon_UnownI,
    [SPECIES_UNOWN_J] = gMonIcon_UnownJ,
    [SPECIES_UNOWN_K] = gMonIcon_UnownK,
    [SPECIES_UNOWN_L] = gMonIcon_UnownL,
    [SPECIES_UNOWN_M] = gMonIcon_UnownM,
    [SPECIES_UNOWN_N] = gMonIcon_UnownN,
    [SPECIES_UNOWN_O] = gMonIcon_UnownO,
    [SPECIES_UNOWN_P] = gMonIcon_UnownP,
    [SPECIES_UNOWN_Q] = gMonIcon_UnownQ,
    [SPECIES_UNOWN_R] = gMonIcon_UnownR,
    [SPECIES_UNOWN_S] = gMonIcon_UnownS,
    [SPECIES_UNOWN_T] = gMonIcon_UnownT,
    [SPECIES_UNOWN_U] = gMonIcon_UnownU,
    [SPECIES_UNOWN_V] = gMonIcon_UnownV,
    [SPECIES_UNOWN_W] = gMonIcon_UnownW,
    [SPECIES_UNOWN_X] = gMonIcon_UnownX,
    [SPECIES_UNOWN_Y] = gMonIcon_UnownY,
    [SPECIES_UNOWN_Z] = gMonIcon_UnownZ,
    [SPECIES_UNOWN_EMARK] = gMonIcon_UnownExclamationMark,
    [SPECIES_UNOWN_QMARK] = gMonIcon_UnownQuestionMark,
};

const u8 gMonIconPaletteIndices[] =
{
    [SPECIES_NONE] = 0,
    [SPECIES_BULBASAUR] = 1,
    [SPECIES_IVYSAUR] = 1,
    [SPECIES_VENUSAUR] = 1,
    [SPECIES_CHARMANDER] = 0,
    [SPECIES_CHARMELEON] = 0,
    [SPECIES_CHARIZARD] = 0,
    [SPECIES_SQUIRTLE] = 0,
    [SPECIES_WARTORTLE] = 2,
    [SPECIES_BLASTOISE] = 2,
    [SPECIES_CATERPIE] = 1,
    [SPECIES_METAPOD] = 1,
    [SPECIES_BUTTERFREE] = 0,
    [SPECIES_WEEDLE] = 1,
    [SPECIES_KAKUNA] = 2,
    [SPECIES_BEEDRILL] = 2,
    [SPECIES_PIDGEY] = 0,
    [SPECIES_PIDGEOTTO] = 0,
    [SPECIES_PIDGEOT] = 0,
    [SPECIES_RATTATA] = 2,
    [SPECIES_RATICATE] = 1,
    [SPECIES_SPEAROW] = 0,
    [SPECIES_FEAROW] = 0,
    [SPECIES_EKANS] = 2,
    [SPECIES_ARBOK] = 2,
    [SPECIES_PIKACHU] = 2,
    [SPECIES_RAICHU] = 0,
    [SPECIES_SANDSHREW] = 2,
    [SPECIES_SANDSLASH] = 2,
    [SPECIES_NIDORAN_F] = 2,
    [SPECIES_NIDORINA] = 2,
    [SPECIES_NIDOQUEEN] = 2,
    [SPECIES_NIDORAN_M] = 2,
    [SPECIES_NIDORINO] = 2,
    [SPECIES_NIDOKING] = 2,
    [SPECIES_CLEFAIRY] = 0,
    [SPECIES_CLEFABLE] = 0,
    [SPECIES_VULPIX] = 2,
    [SPECIES_NINETALES] = 1,
    [SPECIES_JIGGLYPUFF] = 0,
    [SPECIES_WIGGLYTUFF] = 0,
    [SPECIES_ZUBAT] = 2,
    [SPECIES_GOLBAT] = 2,
    [SPECIES_ODDISH] = 1,
    [SPECIES_GLOOM] = 0,
    [SPECIES_VILEPLUME] = 0,
    [SPECIES_PARAS] = 0,
    [SPECIES_PARASECT] = 0,
    [SPECIES_VENONAT] = 0,
    [SPECIES_VENOMOTH] = 2,
    [SPECIES_DIGLETT] = 2,
    [SPECIES_DUGTRIO] = 2,
    [SPECIES_MEOWTH] = 1,
    [SPECIES_PERSIAN] = 1,
    [SPECIES_PSYDUCK] = 1,
    [SPECIES_GOLDUCK] = 2,
    [SPECIES_MANKEY] = 1,
    [SPECIES_PRIMEAPE] = 2,
    [SPECIES_GROWLITHE] = 0,
    [SPECIES_ARCANINE] = 0,
    [SPECIES_POLIWAG] = 0,
    [SPECIES_POLIWHIRL] = 0,
    [SPECIES_POLIWRATH] = 0,
    [SPECIES_ABRA] = 2,
    [SPECIES_KADABRA] = 2,
    [SPECIES_ALAKAZAM] = 2,
    [SPECIES_MACHOP] = 0,
    [SPECIES_MACHOKE] = 2,
    [SPECIES_MACHAMP] = 0,
    [SPECIES_BELLSPROUT] = 1,
    [SPECIES_WEEPINBELL] = 1,
    [SPECIES_VICTREEBEL] = 1,
    [SPECIES_TENTACOOL] = 2,
    [SPECIES_TENTACRUEL] = 2,
    [SPECIES_GEODUDE] = 1,
    [SPECIES_GRAVELER] = 1,
    [SPECIES_GOLEM] = 1,
    [SPECIES_PONYTA] = 0,
    [SPECIES_RAPIDASH] = 0,
    [SPECIES_SLOWPOKE] = 0,
    [SPECIES_SLOWBRO] = 0,
    [SPECIES_MAGNEMITE] = 0,
    [SPECIES_MAGNETON] = 0,
    [SPECIES_FARFETCHD] = 1,
    [SPECIES_DODUO] = 2,
    [SPECIES_DODRIO] = 2,
    [SPECIES_SEEL] = 2,
    [SPECIES_DEWGONG] = 2,
    [SPECIES_GRIMER] = 2,
    [SPECIES_MUK] = 2,
    [SPECIES_SHELLDER] = 2,
    [SPECIES_CLOYSTER] = 2,
    [SPECIES_GASTLY] = 2,
    [SPECIES_HAUNTER] = 2,
    [SPECIES_GENGAR] = 2,
    [SPECIES_ONIX] = 2,
    [SPECIES_DROWZEE] = 2,
    [SPECIES_HYPNO] = 1,
    [SPECIES_KRABBY] = 2,
    [SPECIES_KINGLER] = 2,
    [SPECIES_VOLTORB] = 0,
    [SPECIES_ELECTRODE] = 0,
    [SPECIES_EXEGGCUTE] = 0,
    [SPECIES_EXEGGUTOR] = 1,
    [SPECIES_CUBONE] = 1,
    [SPECIES_MAROWAK] = 1,
    [SPECIES_HITMONLEE] = 2,
    [SPECIES_HITMONCHAN] = 2,
    [SPECIES_LICKITUNG] = 1,
    [SPECIES_KOFFING] = 2,
    [SPECIES_WEEZING] = 2,
    [SPECIES_RHYHORN] = 1,
    [SPECIES_RHYDON] = 1,
    [SPECIES_CHANSEY] = 0,
    [SPECIES_TANGELA] = 0,
    [SPECIES_KANGASKHAN] = 1,
    [SPECIES_HORSEA] = 0,
    [SPECIES_SEADRA] = 0,
    [SPECIES_GOLDEEN] = 0,
    [SPECIES_SEAKING] = 0,
    [SPECIES_STARYU] = 2,
    [SPECIES_STARMIE] = 2,
    [SPECIES_MR_MIME] = 0,
    [SPECIES_SCYTHER] = 1,
    [SPECIES_JYNX] = 2,
    [SPECIES_ELECTABUZZ] = 1,
    [SPECIES_MAGMAR] = 0,
    [SPECIES_PINSIR] = 2,
    [SPECIES_TAUROS] = 2,
    [SPECIES_MAGIKARP] = 0,
    [SPECIES_GYARADOS] = 0,
    [SPECIES_LAPRAS] = 2,
    [SPECIES_DITTO] = 2,
    [SPECIES_EEVEE] = 2,
    [SPECIES_VAPOREON] = 0,
    [SPECIES_JOLTEON] = 0,
    [SPECIES_FLAREON] = 0,
    [SPECIES_PORYGON] = 0,
    [SPECIES_OMANYTE] = 0,
    [SPECIES_OMASTAR] = 0,
    [SPECIES_KABUTO] = 2,
    [SPECIES_KABUTOPS] = 2,
    [SPECIES_AERODACTYL] = 0,
    [SPECIES_SNORLAX] = 1,
    [SPECIES_ARTICUNO] = 0,
    [SPECIES_ZAPDOS] = 0,
    [SPECIES_MOLTRES] = 0,
    [SPECIES_DRATINI] = 0,
    [SPECIES_DRAGONAIR] = 0,
    [SPECIES_DRAGONITE] = 2,
    [SPECIES_MEWTWO] = 2,
    [SPECIES_MEW] = 0,
    [SPECIES_CHIKORITA] = 1,
    [SPECIES_BAYLEEF] = 1,
    [SPECIES_MEGANIUM] = 1,
    [SPECIES_CYNDAQUIL] = 1,
    [SPECIES_QUILAVA] = 1,
    [SPECIES_TYPHLOSION] = 1,
    [SPECIES_TOTODILE] = 2,
    [SPECIES_CROCONAW] = 2,
    [SPECIES_FERALIGATR] = 2,
    [SPECIES_SENTRET] = 2,
    [SPECIES_FURRET] = 2,
    [SPECIES_HOOTHOOT] = 2,
    [SPECIES_NOCTOWL] = 2,
    [SPECIES_LEDYBA] = 0,
    [SPECIES_LEDIAN] = 0,
    [SPECIES_SPINARAK] = 1,
    [SPECIES_ARIADOS] = 0,
    [SPECIES_CROBAT] = 2,
    [SPECIES_CHINCHOU] = 2,
    [SPECIES_LANTURN] = 0,
    [SPECIES_PICHU] = 0,
    [SPECIES_CLEFFA] = 0,
    [SPECIES_IGGLYBUFF] = 1,
    [SPECIES_TOGEPI] = 2,
    [SPECIES_TOGETIC] = 2,
    [SPECIES_NATU] = 0,
    [SPECIES_XATU] = 0,
    [SPECIES_MAREEP] = 2,
    [SPECIES_FLAAFFY] = 0,
    [SPECIES_AMPHAROS] = 0,
    [SPECIES_BELLOSSOM] = 1,
    [SPECIES_MARILL] = 2,
    [SPECIES_AZUMARILL] = 2,
    [SPECIES_SUDOWOODO] = 1,
    [SPECIES_POLITOED] = 1,
    [SPECIES_HOPPIP] = 1,
    [SPECIES_SKIPLOOM] = 1,
    [SPECIES_JUMPLUFF] = 2,
    [SPECIES_AIPOM] = 2,
    [SPECIES_SUNKERN] = 1,
    [SPECIES_SUNFLORA] = 1,
    [SPECIES_YANMA] = 1,
    [SPECIES_WOOPER] = 0,
    [SPECIES_QUAGSIRE] = 0,
    [SPECIES_ESPEON] = 2,
    [SPECIES_UMBREON] = 2,
    [SPECIES_MURKROW] = 2,
    [SPECIES_SLOWKING] = 0,
    [SPECIES_MISDREAVUS] = 0,
    [SPECIES_UNOWN] = 0,
    [SPECIES_WOBBUFFET] = 0,
    [SPECIES_GIRAFARIG] = 1,
    [SPECIES_PINECO] = 0,
    [SPECIES_FORRETRESS] = 2,
    [SPECIES_DUNSPARCE] = 2,
    [SPECIES_GLIGAR] = 2,
    [SPECIES_STEELIX] = 0,
    [SPECIES_SNUBBULL] = 0,
    [SPECIES_GRANBULL] = 2,
    [SPECIES_QWILFISH] = 0,
    [SPECIES_SCIZOR] = 0,
    [SPECIES_SHUCKLE] = 1,
    [SPECIES_HERACROSS] = 2,
    [SPECIES_SNEASEL] = 0,
    [SPECIES_TEDDIURSA] = 0,
    [SPECIES_URSARING] = 2,
    [SPECIES_SLUGMA] = 0,
    [SPECIES_MAGCARGO] = 0,
    [SPECIES_SWINUB] = 2,
    [SPECIES_PILOSWINE] = 2,
    [SPECIES_CORSOLA] = 0,
    [SPECIES_REMORAID] = 0,
    [SPECIES_OCTILLERY] = 0,
    [SPECIES_DELIBIRD] = 0,
    [SPECIES_MANTINE] = 2,
    [SPECIES_SKARMORY] = 0,
    [SPECIES_HOUNDOUR] = 0,
    [SPECIES_HOUNDOOM] = 0,
    [SPECIES_KINGDRA] = 0,
    [SPECIES_PHANPY] = 0,
    [SPECIES_DONPHAN] = 0,
    [SPECIES_PORYGON2] = 0,
    [SPECIES_STANTLER] = 2,
    [SPECIES_SMEARGLE] = 1,
    [SPECIES_TYROGUE] = 2,
    [SPECIES_HITMONTOP] = 2,
    [SPECIES_SMOOCHUM] = 1,
    [SPECIES_ELEKID] = 1,
    [SPECIES_MAGBY] = 1,
    [SPECIES_MILTANK] = 1,
    [SPECIES_BLISSEY] = 1,
    [SPECIES_RAIKOU] = 0,
    [SPECIES_ENTEI] = 2,
    [SPECIES_SUICUNE] = 0,
    [SPECIES_LARVITAR] = 1,
    [SPECIES_PUPITAR] = 0,
    [SPECIES_TYRANITAR] = 1,
    [SPECIES_LUGIA] = 0,
    [SPECIES_HO_OH] = 1,
    [SPECIES_CELEBI] = 1,
    [SPECIES_OLD_UNOWN_B] = 0,
    [SPECIES_OLD_UNOWN_C] = 0,
    [SPECIES_OLD_UNOWN_D] = 0,
    [SPECIES_OLD_UNOWN_E] = 0,
    [SPECIES_OLD_UNOWN_F] = 0,
    [SPECIES_OLD_UNOWN_G] = 0,
    [SPECIES_OLD_UNOWN_H] = 0,
    [SPECIES_OLD_UNOWN_I] = 0,
    [SPECIES_OLD_UNOWN_J] = 0,
    [SPECIES_OLD_UNOWN_K] = 0,
    [SPECIES_OLD_UNOWN_L] = 0,
    [SPECIES_OLD_UNOWN_M] = 0,
    [SPECIES_OLD_UNOWN_N] = 0,
    [SPECIES_OLD_UNOWN_O] = 0,
    [SPECIES_OLD_UNOWN_P] = 0,
    [SPECIES_OLD_UNOWN_Q] = 0,
    [SPECIES_OLD_UNOWN_R] = 0,
    [SPECIES_OLD_UNOWN_S] = 0,
    [SPECIES_OLD_UNOWN_T] = 0,
    [SPECIES_OLD_UNOWN_U] = 0,
    [SPECIES_OLD_UNOWN_V] = 0,
    [SPECIES_OLD_UNOWN_W] = 0,
    [SPECIES_OLD_UNOWN_X] = 0,
    [SPECIES_OLD_UNOWN_Y] = 0,
    [SPECIES_OLD_UNOWN_Z] = 0,
    [SPECIES_TREECKO] = 1,
    [SPECIES_GROVYLE] = 0,
    [SPECIES_SCEPTILE] = 1,
    [SPECIES_TORCHIC] = 0,
    [SPECIES_COMBUSKEN] = 0,
    [SPECIES_BLAZIKEN] = 0,
    [SPECIES_MUDKIP] = 0,
    [SPECIES_MARSHTOMP] = 0,
    [SPECIES_SWAMPERT] = 0,
    [SPECIES_POOCHYENA] = 2,
    [SPECIES_MIGHTYENA] = 2,
    [SPECIES_ZIGZAGOON] = 2,
    [SPECIES_LINOONE] = 2,
    [SPECIES_WURMPLE] = 0,
    [SPECIES_SILCOON] = 2,
    [SPECIES_BEAUTIFLY] = 0,
    [SPECIES_CASCOON] = 2,
    [SPECIES_DUSTOX] = 1,
    [SPECIES_LOTAD] = 1,
    [SPECIES_LOMBRE] = 1,
    [SPECIES_LUDICOLO] = 1,
    [SPECIES_SEEDOT] = 1,
    [SPECIES_NUZLEAF] = 1,
    [SPECIES_SHIFTRY] = 0,
    [SPECIES_NINCADA] = 1,
    [SPECIES_NINJASK] = 1,
    [SPECIES_SHEDINJA] = 1,
    [SPECIES_TAILLOW] = 2,
    [SPECIES_SWELLOW] = 2,
    [SPECIES_SHROOMISH] = 1,
    [SPECIES_BRELOOM] = 1,
    [SPECIES_SPINDA] = 1,
    [SPECIES_WINGULL] = 0,
    [SPECIES_PELIPPER] = 0,
    [SPECIES_SURSKIT] = 2,
    [SPECIES_MASQUERAIN] = 0,
    [SPECIES_WAILMER] = 2,
    [SPECIES_WAILORD] = 0,
    [SPECIES_SKITTY] = 0,
    [SPECIES_DELCATTY] = 2,
    [SPECIES_KECLEON] = 1,
    [SPECIES_BALTOY] = 1,
    [SPECIES_CLAYDOL] = 0,
    [SPECIES_NOSEPASS] = 0,
    [SPECIES_TORKOAL] = 1,
    [SPECIES_SABLEYE] = 2,
    [SPECIES_BARBOACH] = 0,
    [SPECIES_WHISCASH] = 0,
    [SPECIES_LUVDISC] = 0,
    [SPECIES_CORPHISH] = 0,
    [SPECIES_CRAWDAUNT] = 0,
    [SPECIES_FEEBAS] = 2,
    [SPECIES_MILOTIC] = 0,
    [SPECIES_CARVANHA] = 0,
    [SPECIES_SHARPEDO] = 0,
    [SPECIES_TRAPINCH] = 1,
    [SPECIES_VIBRAVA] = 1,
    [SPECIES_FLYGON] = 1,
    [SPECIES_MAKUHITA] = 2,
    [SPECIES_HARIYAMA] = 1,
    [SPECIES_ELECTRIKE] = 1,
    [SPECIES_MANECTRIC] = 0,
    [SPECIES_NUMEL] = 1,
    [SPECIES_CAMERUPT] = 0,
    [SPECIES_SPHEAL] = 2,
    [SPECIES_SEALEO] = 2,
    [SPECIES_WALREIN] = 0,
    [SPECIES_CACNEA] = 1,
    [SPECIES_CACTURNE] = 1,
    [SPECIES_SNORUNT] = 2,
    [SPECIES_GLALIE] = 0,
    [SPECIES_LUNATONE] = 1,
    [SPECIES_SOLROCK] = 0,
    [SPECIES_AZURILL] = 2,
    [SPECIES_SPOINK] = 0,
    [SPECIES_GRUMPIG] = 2,
    [SPECIES_PLUSLE] = 0,
    [SPECIES_MINUN] = 0,
    [SPECIES_MAWILE] = 2,
    [SPECIES_MEDITITE] = 0,
    [SPECIES_MEDICHAM] = 0,
    [SPECIES_SWABLU] = 0,
    [SPECIES_ALTARIA] = 0,
    [SPECIES_WYNAUT] = 0,
    [SPECIES_DUSKULL] = 0,
    [SPECIES_DUSCLOPS] = 0,
    [SPECIES_ROSELIA] = 0,
    [SPECIES_SLAKOTH] = 2,
    [SPECIES_VIGOROTH] = 2,
    [SPECIES_SLAKING] = 1,
    [SPECIES_GULPIN] = 1,
    [SPECIES_SWALOT] = 2,
    [SPECIES_TROPIUS] = 1,
    [SPECIES_WHISMUR] = 0,
    [SPECIES_LOUDRED] = 2,
    [SPECIES_EXPLOUD] = 2,
    [SPECIES_CLAMPERL] = 0,
    [SPECIES_HUNTAIL] = 0,
    [SPECIES_GOREBYSS] = 0,
    [SPECIES_ABSOL] = 0,
    [SPECIES_SHUPPET] = 0,
    [SPECIES_BANETTE] = 0,
    [SPECIES_SEVIPER] = 2,
    [SPECIES_ZANGOOSE] = 0,
    [SPECIES_RELICANTH] = 1,
    [SPECIES_ARON] = 2,
    [SPECIES_LAIRON] = 2,
    [SPECIES_AGGRON] = 2,
    [SPECIES_CASTFORM] = 0,
    [SPECIES_VOLBEAT] = 0,
    [SPECIES_ILLUMISE] = 2,
    [SPECIES_LILEEP] = 2,
    [SPECIES_CRADILY] = 0,
    [SPECIES_ANORITH] = 0,
    [SPECIES_ARMALDO] = 0,
    [SPECIES_RALTS] = 1,
    [SPECIES_KIRLIA] = 1,
    [SPECIES_GARDEVOIR] = 1,
    [SPECIES_BAGON] = 2,
    [SPECIES_SHELGON] = 2,
    [SPECIES_SALAMENCE] = 0,
    [SPECIES_BELDUM] = 0,
    [SPECIES_METANG] = 0,
    [SPECIES_METAGROSS] = 0,
    [SPECIES_REGIROCK] = 2,
    [SPECIES_REGICE] = 2,
    [SPECIES_REGISTEEL] = 2,
    [SPECIES_KYOGRE] = 2,
    [SPECIES_GROUDON] = 0,
    [SPECIES_RAYQUAZA] = 1,
    [SPECIES_LATIAS] = 0,
    [SPECIES_LATIOS] = 2,
    [SPECIES_JIRACHI] = 0,
    [SPECIES_DEOXYS] = 0,
    [SPECIES_CHIMECHO] = 0,
    [SPECIES_EGG] = 1,
    [SPECIES_UNOWN_B] = 0,
    [SPECIES_UNOWN_C] = 0,
    [SPECIES_UNOWN_D] = 0,
    [SPECIES_UNOWN_E] = 0,
    [SPECIES_UNOWN_F] = 0,
    [SPECIES_UNOWN_G] = 0,
    [SPECIES_UNOWN_H] = 0,
    [SPECIES_UNOWN_I] = 0,
    [SPECIES_UNOWN_J] = 0,
    [SPECIES_UNOWN_K] = 0,
    [SPECIES_UNOWN_L] = 0,
    [SPECIES_UNOWN_M] = 0,
    [SPECIES_UNOWN_N] = 0,
    [SPECIES_UNOWN_O] = 0,
    [SPECIES_UNOWN_P] = 0,
    [SPECIES_UNOWN_Q] = 0,
    [SPECIES_UNOWN_R] = 0,
    [SPECIES_UNOWN_S] = 0,
    [SPECIES_UNOWN_T] = 0,
    [SPECIES_UNOWN_U] = 0,
    [SPECIES_UNOWN_V] = 0,
    [SPECIES_UNOWN_W] = 0,
    [SPECIES_UNOWN_X] = 0,
    [SPECIES_UNOWN_Y] = 0,
    [SPECIES_UNOWN_Z] = 0,
    [SPECIES_UNOWN_EMARK] = 0,
    [SPECIES_UNOWN_QMARK] = 0,
};

const struct SpritePalette gMonIconPaletteTable[] =
{
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },
    { battleIconBgPlayer_Pal, BATTLE_ICON_BG_PALETTE_TAG + 0 },
    { battleIconBgOpponent_Pal, BATTLE_ICON_BG_PALETTE_TAG + 1 },
    { gMonIconPalettes[5], POKE_ICON_BASE_PAL_TAG + 5 },
};

static const struct OamData sMonIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
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

u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, bool32 handleDeoxys)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = GetMonIconPtr(species, personality, handleDeoxys),
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    if (species > NUM_SPECIES)
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG;

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u8 CreateMonIconNoPersonality(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, bool32 handleDeoxys)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    iconTemplate.image = GetMonIconTiles(species, handleDeoxys);
    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u16 GetIconSpecies(u16 species, u32 personality)
{
    u16 result;

    if (species == SPECIES_UNOWN)
    {
        u16 letter = GetUnownLetterByPersonality(personality);
        if (letter == 0)
            letter = SPECIES_UNOWN;
        else
            letter += (SPECIES_UNOWN_B - 1);
        result = letter;
    }
    else
    {
        if (species > NUM_SPECIES)
            result = INVALID_ICON_SPECIES;
        else
            result = species;
    }

    return result;
}

u16 GetUnownLetterByPersonality(u32 personality)
{
    if (!personality)
        return 0;
    else
        return GET_UNOWN_LETTER(personality);
}

u16 GetIconSpeciesNoPersonality(u16 species)
{
    u16 value;

    if (MailSpeciesToSpecies(species, &value) == SPECIES_UNOWN)
    {
        if (value == 0)
            value += SPECIES_UNOWN;
        else
            value += (SPECIES_UNOWN_B - 1);
        return value;
    }
    else
    {
        if (species > NUM_SPECIES)
            species = INVALID_ICON_SPECIES;
        return GetIconSpecies(species, 0);
    }
}

const u8 *GetMonIconPtr(u16 species, u32 personality, bool32 handleDeoxys)
{
    return GetMonIconTiles(GetIconSpecies(species, personality), handleDeoxys);
}

void FreeAndDestroyMonIconSprite(struct Sprite *sprite)
{
    FreeAndDestroyMonIconSprite_(sprite);
}

void LoadMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

// unused
void SafeLoadMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalette(u16 species)
{
    u8 palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
}

// unused
void SafeFreeMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void FreeMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void SpriteCB_MonIcon(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

const u8* GetMonIconTiles(u16 species, bool32 handleDeoxys)
{
    const u8* iconSprite = gMonIconTable[species];
    if (species == SPECIES_DEOXYS && handleDeoxys == TRUE)
    {
        iconSprite = (const u8*)(0x400 + (u32)iconSprite); // use the specific Deoxys form icon (Speed in this case)
    }
    return iconSprite;
}

void TryLoadAllMonIconPalettesAtOffset(u16 offset)
{
    s32 i;
    const struct SpritePalette* monIconPalettePtr;

    if (offset <= 0xA0)
    {
        monIconPalettePtr = gMonIconPaletteTable;
        for(i = ARRAY_COUNT(gMonIconPaletteTable) - 1; i >= 0; i--)
        {
            LoadPalette(monIconPalettePtr->data, offset, 0x20);
            offset += 0x10;
            monIconPalettePtr++;
        }
    }
}

u8 GetValidMonIconPalIndex(u16 species)
{
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return gMonIconPaletteIndices[species];
}

u8 GetMonIconPaletteIndexFromSpecies(u16 species)
{
    return gMonIconPaletteIndices[species];
}

const u16* GetValidMonIconPalettePtr(u16 species)
{
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return gMonIconPaletteTable[gMonIconPaletteIndices[species]].data;
}

u8 UpdateMonIconFrame(struct Sprite *sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            RequestSpriteCopy(
                // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                // arithmetic can be performed.
                (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
                sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            sprite->animDelayCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration & 0xFF;
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = TAG_NONE,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
