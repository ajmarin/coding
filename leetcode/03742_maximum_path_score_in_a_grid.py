class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        MIN = -(10**9)
        rows, cols = len(grid), len(grid[0])
        dp = [[[-1] * (k + 1) for c in range(cols)] for r in range(rows)]

        def f(x: int, y: int, c: int) -> int:
            if x < 0 or y < 0:
                return MIN
            if dp[x][y][c] != -1:
                return dp[x][y][c]
            val = grid[x][y]
            cost = c + (val > 0)
            if cost > k:
                dp[x][y][c] = MIN
                return MIN
            val += max(f(x - 1, y, cost), f(x, y - 1, cost)) if x or y else 0
            dp[x][y][c] = val
            return val

        ans = f(rows - 1, cols - 1, 0)
        return -(ans < 0) | ans
