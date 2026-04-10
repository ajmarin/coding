class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        n = len(grid)
        return next(i for i in range(n) if sum(grid[i]) == n - 1)
