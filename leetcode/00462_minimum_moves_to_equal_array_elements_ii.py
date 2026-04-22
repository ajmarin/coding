class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        median = nums[len(nums) >> 1]
        return sum(abs(x - median) for x in nums)
