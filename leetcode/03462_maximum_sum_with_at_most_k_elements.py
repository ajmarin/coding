class Solution:
    def maxSum(self, grid: List[List[int]], limits: List[int], k: int) -> int:
        if not k:
            return 0
        values = []
        for lim, row in zip(limits, grid):
            if lim:
                values.extend(sorted(row)[-lim:])
        values.sort()
        return sum(values[-k:])
