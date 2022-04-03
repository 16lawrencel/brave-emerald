import os
from utils import *

BASE_DIR="graphics/pokemon/battle_icons"

ICON_DIMS = Dims(16, 16)

side_names = [
    "player",
    "opponent"
]

palette_nums = [
    [9, 8, 12],
    [6, 10, 11]
]

for side in range(2):
    mat = [[0] * ICON_DIMS.width for i in range(ICON_DIMS.height)]

    # fill perimeter
    for r in range(ICON_DIMS.height):
        for c in range(ICON_DIMS.width):
            if r == 0 or r == ICON_DIMS.height-1 or c == 0 or c == ICON_DIMS.width-1:
                mat[r][c] = palette_nums[side][0]
            elif r == 1 or r == ICON_DIMS.height-2 or c == 1 or c == ICON_DIMS.width-2:
                mat[r][c] = palette_nums[side][1]
            else:
                mat[r][c] = palette_nums[side][2]


    name = side_names[side]
    with open(f"{BASE_DIR}/battle_icon_bg_{name}.4bpp", "wb") as f:
        vals = pack_tiles(mat, dims=ICON_DIMS)

        val_bytes = b""
        for i in range(0, len(vals), 2):
            # two 4-bit values = 1 byte
            combined_val = int(vals[i] + vals[i+1] * 16)
            val_bytes += combined_val.to_bytes(1, "little")

        f.write(val_bytes)

    os.system(f"""
        tools/gbagfx/gbagfx {BASE_DIR}/battle_icon_bg_{name}.4bpp {BASE_DIR}/battle_icon_bg_{name}.png -width 2
    """)
