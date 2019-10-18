class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        n = len(nums)
        left, right = 0, n
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] == target:
                return mid
            if nums[left] < nums[mid]:
                if nums[left] <= target and target < nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[mid] < target and target <= nums[right - 1]:
                    left = mid + 1
                else:
                    right = mid
        return left if left < n and nums[left] == target else -1