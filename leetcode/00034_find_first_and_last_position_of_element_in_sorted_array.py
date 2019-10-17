class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = 0
        right = len(nums)
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        if left >= len(nums) or nums[left] != target:
            return [-1, -1]
        left_ret = left
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right + 1) >> 1
            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid
        return [left_ret, right]