class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        busy = [False] * 101
        for start, end in nums:
            for i in range(start, end + 1):
                busy[i] = True
        return sum(busy)
