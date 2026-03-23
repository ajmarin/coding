class Solution:
    def minimumRightShifts(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                break
        else:
            return 0
        if nums[-1] > nums[0]:
            return -1
        ans = n - i
        for i in range(i, len(nums) - 1):
            if nums[i + 1] < nums[i]:
                return -1
        return ans
