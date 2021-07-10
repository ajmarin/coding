class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        ans = 0
        maxcol = [0] * len(grid)
        maxrow = [0] * len(grid)
        for index, row in enumerate(grid):
            maxrow[index] = max(row)
            for col, n in enumerate(row):
                maxcol[col] = max(maxcol[col], n)
                ans += n != 0
        return ans + sum(maxcol) + sum(maxrow)

