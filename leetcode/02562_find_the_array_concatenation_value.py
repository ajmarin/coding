class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        res = 0
        while left < right:
            res += int(str(nums[left]) + str(nums[right]))
            left += 1
            right -= 1
        if left == right:
            res += nums[left]
        return res
