class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        rows, cols = len(grid), len(grid[0])
        if grid[0][0] == ")" or grid[-1][-1] == "(" or (rows + cols - 1) & 1:
            return False

        dp = [[0] * cols for _ in range(rows)]
        dp[0][0] = 2
        prev = None

        for r in range(rows):
            row, grid_row = dp[r], grid[r]
            left = 0
            for c in range(cols):
                up = prev[c] if prev else 0
                if grid_row[c] == "(":
                    row[c] |= (left << 1) | (up << 1)
                else:
                    row[c] |= (left >> 1) | (up >> 1)
                left = row[c]
            prev = row

        return bool(dp[-1][-1] & 1)
