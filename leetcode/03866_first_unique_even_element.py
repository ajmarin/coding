class Solution:
    def firstUniqueEven(self, nums: list[int]) -> int:
        counts = [0] * 101
        for n in nums:
            counts[n] += 1
        for n in nums:
            if not n & 1 and counts[n] == 1:
                return n
        return -1
