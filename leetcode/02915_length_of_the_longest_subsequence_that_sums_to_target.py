class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        dp = [0] + [-1001] * target
        for n in nums:
            for i in range(target, n - 1, -1):
                dp[i] = max(dp[i], 1 + dp[i - n])
        return -(dp[target] < 0) | dp[target]
