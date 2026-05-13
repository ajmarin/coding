class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        row_cost = sum(r[c] ^ r[~c] for c in range(cols >> 1) for r in grid)
        col_cost = 0
        for c in range(cols):
            for r in range(rows >> 1):
                col_cost += grid[r][c] != grid[~r][c]
        return min(row_cost, col_cost)
