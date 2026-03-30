class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        left = 0
        for index in range(len(nums)):
            me = nums[index]
            if left + me == total:
                return index
            left += me << 1
        return -1
