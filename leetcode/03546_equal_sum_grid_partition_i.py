class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        rows = [*map(sum, grid)]
        total = sum(rows)
        if total & 1:
            return False
        goal = total >> 1
        return goal in accumulate(rows) or goal in accumulate(map(sum, zip(*grid)))
