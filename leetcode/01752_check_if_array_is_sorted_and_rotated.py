class Solution:
    def check(self, nums: List[int]) -> bool:
        dir_switches = 0
        n = len(nums)
        for i in range(1, n):
            dir_switches += nums[i] < nums[i - 1]
        return dir_switches == 0 or dir_switches == 1 and nums[0] >= nums[-1]
