class Solution:
    def maxSum(self, nums: List[int]) -> int:
        non_negative = [n for n in set(nums) if n >= 0]
        return sum(non_negative) if non_negative else max(nums)

