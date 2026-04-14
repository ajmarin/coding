class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        return sum(nums[i] == 2 * (nums[i - 1] + nums[i + 1]) for i in range(1, n - 1))
