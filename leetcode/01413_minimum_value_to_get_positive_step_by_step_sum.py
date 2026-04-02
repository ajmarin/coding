class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        return 1 + max(-min(accumulate(nums)), 0)
