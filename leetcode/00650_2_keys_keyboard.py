class Solution:
    def minSteps(self, n: int) -> int:
        n += 1
        dp = [1000] * n
        dp[1] = 0
        for i in range(1, n):
            inc = 2
            for j in range(2 * i, n, i):
                dp[j] = min(dp[j], dp[i] + inc)
                inc += 1
        return dp[n - 1]