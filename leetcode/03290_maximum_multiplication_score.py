class Solution:
    def maxScore(self, a: List[int], b: List[int]) -> int:
        n = len(b)

        dp = [[-(10**11)] * (n + 1) for _ in range(5)]
        dp[0][:] = [0] * (n + 1)

        for i, ai in enumerate(a, 1):
            dpi = dp[i]
            for j, bj in enumerate(b, 1):
                dpi[j] = max(ai * bj + dp[i - 1][j - 1], dpi[j - 1])
        return dp[4][n]
