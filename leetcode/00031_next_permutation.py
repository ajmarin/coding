class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        x = len(nums) - 2
        while x >= 0 and nums[x] >= nums[x + 1]:
            x -= 1
        left, right = x + 1, len(nums) - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            right -= 1
            left += 1
        if x < 0:
            return
        left, right = x + 1, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] <= nums[x]:
                left = mid + 1
            else:
                right = mid
        nums[x], nums[left] = nums[left], nums[x]