# Calculate inverse square roots to create table for agility
import math
from itertools import islice

TICK_SPEED_MULTIPLIER = 100000
MAX_SPEED = 2000
ROW_SIZE = 50
tick_speed_list = []

for i in range(MAX_SPEED):
    tick_speed = TICK_SPEED_MULTIPLIER
    if i > 0:
        tick_speed = int(TICK_SPEED_MULTIPLIER / math.sqrt(i))

    tick_speed_list.append(tick_speed)

for i in range(0, len(tick_speed_list), ROW_SIZE):
    print(*tick_speed_list[i:i+ROW_SIZE], sep=', ', end=',\n')

