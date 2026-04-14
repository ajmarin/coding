class Solution:
    def transformArray(self, nums: List[int]) -> List[int]:
        odd = sum(n & 1 for n in nums)
        return [0] * (len(nums) - odd) + [1] * odd
