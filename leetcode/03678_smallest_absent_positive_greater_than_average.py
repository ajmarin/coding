class Solution:
    def smallestAbsent(self, nums: List[int]) -> int:
        avg = sum(nums) / len(nums)
        nums_set = set(nums)
        return next(
            i for i in range(max(floor(avg), 1), 102) if i not in nums_set and i > avg
        )
