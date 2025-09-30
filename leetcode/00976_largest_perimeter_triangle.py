class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        a, b = nums[-2:]
        for i in range(len(nums) - 1, 1, -1):
            a, b = nums[i - 2], a
            c = nums[i]
            if a + b > c:
                return a + b + c
        return 0
