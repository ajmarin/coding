class Solution:
    def findValidElements(self, nums: list[int]) -> list[int]:
        n = len(nums)
        is_valid = [False] * n
        big_left = big_right = 0
        for i in range(len(nums)):
            if nums[i] > big_left:
                is_valid[i] = True
                big_left = nums[i]
            if nums[~i] > big_right:
                is_valid[~i] = True
                big_right = nums[~i]
        return [nums[i] for i in range(n) if is_valid[i]]
