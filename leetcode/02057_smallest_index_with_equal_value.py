class Solution:
    def smallestEqual(self, nums: List[int]) -> int:
        return next((i for i, n in enumerate(nums) if i % 10 == n), -1)
