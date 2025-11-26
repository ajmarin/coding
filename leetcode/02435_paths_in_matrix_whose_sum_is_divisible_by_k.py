MOD = 10**9 + 7


class Solution:
    def numberOfPaths(self, grid: List[List[int]], k: int) -> int:
        rows, cols = len(grid), len(grid[0])
        dp = [[[0] * k for _ in range(cols)] for _ in range(rows)]

        total = 0
        for i in range(rows):
            total = (total + grid[i][0]) % k
            dp[i][0][total] = 1

        total = 0
        for j in range(cols):
            total = (total + grid[0][j]) % k
            dp[0][j][total] = 1

        for i in range(1, rows):
            row = grid[i]
            for j in range(1, cols):
                prev_rem = (k - row[j]) % k
                for rem in range(k):
                    total = dp[i - 1][j][prev_rem] + dp[i][j - 1][prev_rem]
                    dp[i][j][rem] = total % MOD
                    prev_rem = (prev_rem + 1) % k

        return dp[rows - 1][cols - 1][0]
