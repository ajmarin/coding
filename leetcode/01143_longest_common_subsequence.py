class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        text1 = ' ' + text1
        text2 = ' ' + text2
        l1, l2 = len(text1), len(text2)
        dp = [0] * l2
        for i in range(1, l1):
            prev = 0
            for j in range(1, l2):
                tmp = dp[j]
                if text1[i] == text2[j]:
                    dp[j] = prev + 1
                else:
                    dp[j] = max(dp[j], dp[j - 1])
                prev = tmp
        return dp[-1]