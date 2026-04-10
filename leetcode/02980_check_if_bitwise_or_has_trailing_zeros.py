class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        return len([x for x in nums if not x & 1]) > 1
