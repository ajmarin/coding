class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        lena, lenb = len(A), len(B)
        dp = [[0] * (lenb + 1) for _ in range(lena + 1)]
        for i, a in enumerate(A):
            for j, b in enumerate(B):
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j], dp[i][j] + (a == b))
        return dp[lena][lenb]