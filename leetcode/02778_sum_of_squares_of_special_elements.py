class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        n = len(nums)
        return sum(v * v for i, v in enumerate(nums, 1) if n % i == 0)
