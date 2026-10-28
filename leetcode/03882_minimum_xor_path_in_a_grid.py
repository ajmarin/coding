class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        prev = grid[0][0]
        for r in range(1, rows):
            prev ^= grid[r][0]
            grid[r][0] = {prev}
        prev = grid[0][0]
        for c in range(1, cols):
            prev ^= grid[0][c]
            grid[0][c] = {prev}
        grid[0][0] = {grid[0][0]}
        for r in range(1, rows):
            row = grid[r]
            for c in range(1, cols):
                v = row[c]
                row[c] = {v ^ l for l in row[c - 1]} | {v ^ u for u in grid[r - 1][c]}
        return min(grid[-1][-1])
