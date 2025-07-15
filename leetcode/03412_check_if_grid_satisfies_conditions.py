class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if (i and val != grid[i - 1][j]) or (j and val == grid[i][j - 1]):
                    return False
        return True

