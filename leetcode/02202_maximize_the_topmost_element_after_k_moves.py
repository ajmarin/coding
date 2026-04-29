class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        if k == 0:
            return nums[0]
        if len(nums) == 1 and k & 1:
            return -1
        return max(max(nums[: k - 1], default=-1), -1 if k >= len(nums) else nums[k])
