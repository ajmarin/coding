class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        solution, size = 0, 1
        for i in range(len(nums)):
            if i and nums[i] > nums[i - 1]:
                size += 1
            else:
                size = 1
            solution = max(solution, size)
        return solution