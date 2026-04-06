class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        curr = 0
        for i, n in enumerate(nums):
            if 2 * curr == total - n:
                return i
            curr += n
        return -1
