class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        return sum(n * comb(len(nums) - 1, i) for i, n in enumerate(nums)) % 10
