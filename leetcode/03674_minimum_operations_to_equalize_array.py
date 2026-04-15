class Solution:
    def minOperations(self, nums: List[int]) -> int:
        return +(len(set(nums)) > 1)
