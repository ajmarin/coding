class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        vlow = [[inf] * cols for _ in range(rows)]
        vhigh = [[-inf] * cols for _ in range(rows)]
        vlow[0][0] = vhigh[0][0] = grid[0][0]

        def update(r, c, l, h):
            a, b = l * grid[r][c], h * grid[r][c]
            if a > b:
                a, b = b, a
            vlow[r][c] = a if a < vlow[r][c] else vlow[r][c]
            vhigh[r][c] = b if b > vhigh[r][c] else vhigh[r][c]

        for r in range(1, rows):
            update(r, 0, vlow[r - 1][0], vhigh[r - 1][0])
        for c in range(1, cols):
            update(0, c, vlow[0][c - 1], vhigh[0][c - 1])
        for r in range(1, rows):
            for c in range(1, cols):
                update(r, c, vlow[r - 1][c], vhigh[r - 1][c])
                update(r, c, vlow[r][c - 1], vhigh[r][c - 1])
        highest = vhigh[-1][-1]
        return highest % (10**9 + 7) if highest >= 0 else -1
