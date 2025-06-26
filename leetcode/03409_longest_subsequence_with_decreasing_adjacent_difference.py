MAX_N = 301

class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        ans = 0
        dp = [[0 for i in range(MAX_N)] for j in range(MAX_N)]
        for n in nums:
            best = 0
            for diff in range(max(n, 300 - n), -1, -1):
                lower = n - diff
                if lower >= 0:
                    best = max(best, dp[lower][diff] + 1)
                higher = n + diff
                if higher < MAX_N:
                    best = max(best, dp[higher][diff] + 1)
                dp[n][diff] = best
            ans = max(ans, best)
        return ans

