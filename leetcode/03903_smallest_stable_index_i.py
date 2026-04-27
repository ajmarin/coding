class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        biggest = nums[0]
        for i in range(len(nums)):
            biggest = biggest if biggest > nums[i] else nums[i]
            if biggest - min(nums[i:]) <= k:
                return i
        return -1
