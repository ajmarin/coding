class Solution:
    def findNonMinOrMax(self, nums: List[int]) -> int:
        low, high = min(nums), max(nums)
        return next((n for n in nums if n not in (low, high)), -1)
