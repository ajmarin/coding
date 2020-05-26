class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        lena, lenb = len(A), len(B)
        dp = [0] * (lenb + 1)
        for i, a in enumerate(A):
            prev = dp[0]
            for j, b in enumerate(B):
                tmp = dp[j + 1]
                dp[j + 1] = max(dp[j + 1], dp[j], prev + (a == b))
                prev = tmp
        return dp[lenb]