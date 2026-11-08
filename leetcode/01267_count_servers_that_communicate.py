class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        cols = len(grid[0])
        row_count = [0] * len(grid)
        col_count = [0] * cols

        for r, row in enumerate(grid):
            for c, val in enumerate(row):
                if val:
                    row_count[r] += val
                    col_count[c] += val

        return sum(
            (
                rc
                if rc > 1
                else sum(1 for c in range(cols) if grid[r][c] and col_count[c] > 1)
            )
            for r, rc in enumerate(row_count)
        )
