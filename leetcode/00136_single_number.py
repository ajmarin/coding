from collections import Counter
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return next(k for k, v in Counter(nums).items() if v == 1)