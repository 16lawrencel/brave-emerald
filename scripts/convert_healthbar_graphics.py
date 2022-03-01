import numpy as np
import os
import sys
from utils import *

np.set_printoptions(threshold=sys.maxsize)

HEALTHBOX_DIMS = Dims(64, 64)

# change from player -> opponent for opponent box
SUBJECT = "opponent"
IN_FILE = f"graphics/battle_interface/healthbox_doubles_{SUBJECT}.4bpp"
OUT_FILE = f"graphics/battle_interface/healthbox_triples_{SUBJECT}.4bpp"

vals = []

with open(IN_FILE, "rb") as f:
    bt = f.read()
    vals = convert_bytes_to_vals(bt)

unpacked_vals = unpack_tiles(vals, dims=HEALTHBOX_DIMS)
grid = np.array(unpacked_vals).reshape(HEALTHBOX_DIMS)

# shift down 4 times
for k in range(4):
    for i in range(k+8, k, -1):
        grid[i] = grid[i-1].copy()

    st = k + 33
    for i in range(st+8, st, -1):
        grid[i] = grid[i-1].copy()

bt = convert_vals_to_bytes(pack_tiles(grid.flatten(), dims=HEALTHBOX_DIMS))

with open(OUT_FILE, "wb") as f:
    f.write(bt)

os.system(f"""
    tools/gbagfx/gbagfx graphics/battle_interface/healthbox_triples_{SUBJECT}.4bpp graphics/battle_interface/healthbox_triples_{SUBJECT}.png -width 8 -palette graphics/battle_interface/ball_status_bar.gbapal
""")

