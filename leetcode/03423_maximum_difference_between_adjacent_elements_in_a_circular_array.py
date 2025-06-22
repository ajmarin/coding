class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        return max(abs(nums[(i + 1) % n] - x) for i, x in enumerate(nums))

