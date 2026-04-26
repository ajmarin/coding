class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        ordered = sorted(nums)
        for left in range(n):
            if ordered[left] != nums[left]:
                break
        if left == n - 1:
            return 0
        for right in range(n - 1, -1, -1):
            if ordered[right] != nums[right]:
                break
        return right - left + 1
