import numpy as np
import os
import sys

np.set_printoptions(threshold=sys.maxsize)


# change from player -> opponent for opponent box
SUBJECT = "opponent"
IN_FILE = f"graphics/battle_interface/healthbox_doubles_{SUBJECT}.4bpp"
OUT_FILE = f"graphics/battle_interface/healthbox_triples_{SUBJECT}.4bpp"
PALETTE_SIZE = 16
HEIGHT = 64
WIDTH = 64
GRID_HEIGHT = 8
GRID_WIDTH = 8


def convert_bytes_to_vals(bt):
    vals = []
    for b in bt:
        vals.append(b % PALETTE_SIZE)
        vals.append(b // PALETTE_SIZE)
    return vals

def unpack_chunks(vals):
    """
    The 4bpp file is stored in 8x8 chunks, so we unpack it into the
    more standard 64x64 grid format.
    """
    ret = []
    grid = np.array(vals).reshape((HEIGHT, WIDTH))
    for row_start in range(0, HEIGHT, GRID_HEIGHT):
        for col_start in range(0, WIDTH, GRID_WIDTH):
            for r in range(GRID_HEIGHT):
                for c in range(GRID_WIDTH):
                    ret.append(grid[row_start+r][col_start+c])
    return ret

def pack_chunks(vals):
    grid = np.zeros((HEIGHT, WIDTH))
    idx = 0
    for row_start in range(0, HEIGHT, GRID_HEIGHT):
        for col_start in range(0, WIDTH, GRID_WIDTH):
            for r in range(GRID_HEIGHT):
                for c in range(GRID_WIDTH):
                    grid[row_start+r][col_start+c] = vals[idx]
                    idx += 1
    return grid.flatten()

def convert_vals_to_bytes(vals):
    bt = b""
    for i in range(0, len(vals), 2):
        v1, v2 = vals[i], vals[i+1]
        v = int(v1 + v2 * PALETTE_SIZE)
        bt += v.to_bytes(1, 'little')
    return bt

vals = []

with open(IN_FILE, "rb") as f:
    bt = f.read()
    vals = convert_bytes_to_vals(bt)

unpacked_vals = unpack_chunks(vals)
grid = np.array(unpacked_vals).reshape((WIDTH, HEIGHT))

# shift down 4 times
for k in range(4):
    for i in range(k+8, k, -1):
        grid[i] = grid[i-1].copy()

    st = k + 33
    for i in range(st+8, st, -1):
        grid[i] = grid[i-1].copy()

bt = convert_vals_to_bytes(pack_chunks(grid.flatten()))

with open(OUT_FILE, "wb") as f:
    f.write(bt)

os.system(f"""
    tools/gbagfx/gbagfx graphics/battle_interface/healthbox_triples_{SUBJECT}.4bpp graphics/battle_interface/healthbox_triples_{SUBJECT}.png -width 8 -palette graphics/battle_interface/ball_status_bar.gbapal
""")

