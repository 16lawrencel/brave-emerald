import numpy as np
from collections import namedtuple

Dims = namedtuple("Dimensions", "height width")

TILE_DIMS = Dims(8, 8)
PALETTE_SIZE = 16

def convert_bytes_to_vals(bt):
    vals = []
    for b in bt:
        vals.append(b % PALETTE_SIZE)
        vals.append(b // PALETTE_SIZE)
    return vals

def convert_vals_to_bytes(vals):
    bt = b""
    for i in range(0, len(vals), 2):
        v1, v2 = vals[i], vals[i+1]
        v = int(v1 + v2 * PALETTE_SIZE)
        bt += v.to_bytes(1, 'little')
    return bt

def unpack_tiles(vals, dims: Dims):
    """
    Input: values in "packed" tile format: e.g. if dims = 4x4 and
    tile_dims = 2x2, then input
    would have indices like this:
        0  1  4  5
        2  3  6  7
        8  9  12 13
        10 11 14 15
    Output: a grid with dimensions dims.height x dims.width with
    the unpacked values.
    """
    grid = np.zeros(dims)
    idx = 0
    for row_start in range(0, dims.height, TILE_DIMS.height):
        for col_start in range(0, dims.width, TILE_DIMS.width):
            for r in range(TILE_DIMS.height):
                for c in range(TILE_DIMS.width):
                    grid[row_start+r][col_start+c] = vals[idx]
                    idx += 1
    return grid

def pack_tiles(vals, dims: Dims):
    """
    Input: array with dims.height x dims.width values.
    Output: "packed" array (as described in unpack_tiles).
    """
    ret = [0] * (dims.height * dims.width)
    idx = 0
    grid = np.array(vals).reshape(dims)
    for row_start in range(0, dims.height, TILE_DIMS.height):
        for col_start in range(0, dims.width, TILE_DIMS.width):
            for r in range(TILE_DIMS.height):
                for c in range(TILE_DIMS.width):
                    ret[idx] = grid[row_start+r][col_start+c]
                    idx += 1
    return ret

