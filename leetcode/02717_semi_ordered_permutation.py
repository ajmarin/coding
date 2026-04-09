class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        first, last = nums.index(1), nums.index(len(nums))
        return first + len(nums) - last - 1 - (last < first)
