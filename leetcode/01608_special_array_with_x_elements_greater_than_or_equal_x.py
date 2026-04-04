class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        return next((x for x in range(n + 1) if n - bisect_left(nums, x) == x), -1)
