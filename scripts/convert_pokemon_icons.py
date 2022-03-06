import os
import sys
import json
import numpy as np
from utils import *

np.set_printoptions(threshold=sys.maxsize)

ICON_PALETTE_DIR = "graphics/pokemon/icon_palettes"

ICON_DIMS = Dims(64, 32)
SMALL_DIMS = Dims(16, 16)

with open("scripts/pokemon_icon_data.json", "r") as f:
    pokemon_icon_data = json.load(f)

for pokemon in pokemon_icon_data:
    print(pokemon)

    palette_num = pokemon_icon_data[pokemon]["palette_num"]
    icon_x = pokemon_icon_data[pokemon]["icon_x"]
    icon_y = pokemon_icon_data[pokemon]["icon_y"]
    icon_file = pokemon_icon_data[pokemon]["icon_file"]
    pokemon_dir = "/".join(icon_file.split("/")[:-1])

    with open(f"{pokemon_dir}/icon.4bpp", "rb") as f:
        bt = f.read()
        unpacked_vals = unpack_tiles(convert_bytes_to_vals(bt), dims=ICON_DIMS)
        grid = np.array(unpacked_vals).reshape(ICON_DIMS)
        new_grid = grid[icon_y:icon_y+SMALL_DIMS.height, icon_x:icon_x+SMALL_DIMS.width]
        new_bt = convert_vals_to_bytes(pack_tiles(new_grid, dims=SMALL_DIMS))

    with open(f"{pokemon_dir}/battle_icon.4bpp", "wb") as f:
        f.write(new_bt)

    png_width = SMALL_DIMS.width // TILE_DIMS.width
    os.system(f"""
        tools/gbagfx/gbagfx {pokemon_dir}/battle_icon.4bpp {pokemon_dir}/battle_icon.png -width {png_width} -palette {ICON_PALETTE_DIR}/pal{palette_num}.gbapal
    """)

