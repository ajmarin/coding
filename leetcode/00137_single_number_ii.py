class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return next(n for n, c in Counter(nums).items() if c == 1)
