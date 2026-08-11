class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        prefix_sum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1] + 1:
                break
            prefix_sum += nums[i]

        nums_set = set(nums)
        return next(x for x in range(prefix_sum, 10_000) if x not in nums_set)
