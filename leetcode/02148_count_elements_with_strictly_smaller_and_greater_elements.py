class Solution:
    def countElements(self, nums: List[int]) -> int:
        low, high = min(nums), max(nums)
        return sum(low != n != high for n in nums)
