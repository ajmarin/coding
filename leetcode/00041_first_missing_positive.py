class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums) + 1
        nums.append(0)
        for index, v in enumerate(nums):
            if not 0 < v < n:
                nums[index] = 0
        for v in nums:
            nums[v % n] += n
        for i, v in enumerate(nums[1:]):
            if v < n:
                return i + 1
        return n

