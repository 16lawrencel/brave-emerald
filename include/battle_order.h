#ifndef GUARD_BATTLE_ORDER_H
#define GUARD_BATTLE_ORDER_H

#define DEFAULT_MOVE_SPEED 6
#define FAST_MOVE_SPEED 3
#define MAX_BATTLER_SPEED 2000

extern const u32 battlerTickSpeedTable[];

u8 GetBattlerWithLowestTicks(void);
u32 CalculateAddedTicks(u8 battlerId, u8 moveSpeed);
void CreateAllBattleOrderMonIconSprites(void);
void UpdateBattleOrderMonIconSprites(void);
void FreeBattleOrderMonIconSprites(void);

#endif // GUARD_BATTLE_ORDER_H