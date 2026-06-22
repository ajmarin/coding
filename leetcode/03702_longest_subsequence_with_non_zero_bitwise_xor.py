class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        if not any(nums):
            return 0
        x = 0
        for n in nums:
            x ^= n
        return len(nums) - (x == 0)
