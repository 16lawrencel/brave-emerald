import os
import sys
import json
import numpy as np
from utils import *

np.set_printoptions(threshold=sys.maxsize)

BASE_DIR = "graphics/pokemon"

ICON_DIMS = Dims(64, 32)
SMALL_DIMS = Dims(16, 16)

with open("scripts/pokemon_icon_data.json", "r") as f:
    pokemon_icon_data = json.load(f)

pokemon_list = os.listdir(BASE_DIR)
pokemon_list.remove("icon_palettes")
pokemon_list.remove("question_mark")
pokemon_list.remove("unown")
for letter in os.listdir(os.path.join(BASE_DIR, "unown")):
    if os.path.isdir(os.path.join(BASE_DIR, "unown", letter)):
        pokemon_list.append(f"unown_{letter}")

for pokemon in pokemon_list:
    if pokemon.startswith("unown"):
        sp = pokemon.split("_")
        pokemon_dir = os.path.join(BASE_DIR, *pokemon.split("_", maxsplit=1))
    else:
        pokemon_dir = os.path.join(BASE_DIR, pokemon)

    if not os.path.isdir(pokemon_dir):
        continue

    if pokemon not in pokemon_icon_data:
        raise Exception(f"Pokemon {pokemon} not found in POKEMON_ICON_DATA")

    print(pokemon)

    palette_num = pokemon_icon_data[pokemon]["palette_num"]
    icon_x = pokemon_icon_data[pokemon]["icon_x"]
    icon_y = pokemon_icon_data[pokemon]["icon_y"]
    icon_palette_dir = os.path.join(BASE_DIR, "icon_palettes")

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
        tools/gbagfx/gbagfx {pokemon_dir}/battle_icon.4bpp {pokemon_dir}/battle_icon.png -width {png_width} -palette {icon_palette_dir}/icon_palette_{palette_num}.gbapal
    """)

