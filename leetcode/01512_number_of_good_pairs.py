class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        return sum(c * (c - 1) for c in Counter(nums).values()) >> 1
