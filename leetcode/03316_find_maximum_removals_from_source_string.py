class Solution:
    def maxRemovals(self, source: str, pattern: str, targetIndices: List[int]) -> int:
        s, p = len(source), len(pattern)
        targets = set(targetIndices)
        dp = [0] + [-inf] * p
        for i in range(s):
            add = i in targets
            char = source[i]
            for pat, j in zip(pattern[::-1], range(p, 0, -1)):
                dp[j] += add
                if pat == char:
                    dp[j] = dp[j] if dp[j] > dp[j - 1] else dp[j - 1]
            dp[0] += add
        return dp[-1]
