class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_reached = 0
        for i in range(len(nums)):
            if i > max_reached:
                return False
            max_reached = max(max_reached, i + nums[i])
        return True