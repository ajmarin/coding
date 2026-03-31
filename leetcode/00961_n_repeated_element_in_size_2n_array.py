class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        return next(num for num, c in Counter(nums).items() if c > 1)
