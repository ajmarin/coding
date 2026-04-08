class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        sums = set()
        nums.sort()
        for i in range(len(nums) // 2):
            sums.add(nums[i] + nums[~i])
        return len(sums)
