class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        low, smallest = [0] * n, 10**9
        for i in range(n - 1, -1, -1):
            low[i] = smallest = smallest if smallest < nums[i] else nums[i]
        biggest = 0
        for i in range(n):
            biggest = biggest if biggest > nums[i] else nums[i]
            if biggest - low[i] <= k:
                return i
        return -1
