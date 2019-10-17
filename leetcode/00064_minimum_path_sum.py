class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        if rows == 0:
            return 0
        cols = len(grid[0])
        for row in range(rows):
            for col in range(cols):
                if row > 0 and col > 0:
                    grid[row][col] += min(grid[row - 1][col], grid[row][col - 1])
                elif row + col > 0:
                    grid[row][col] += grid[row - (col == 0)][col - (row == 0)] 
        return grid[rows - 1][cols - 1]