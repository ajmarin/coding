class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0]) if grid else 0
        ans = 0
        for i in range(2, rows):
            for j in range(2, cols):
                nums = set(grid[ii][jj] for ii in range(i - 2, i + 1) for jj in range(j - 2, j + 1))
                if any(x not in nums for x in range(1, 10)):
                    continue
                ans += (
                    grid[i - 2][j - 2] + grid[i - 2][j - 1] + grid[i - 2][j] == # first row
                    grid[i - 1][j - 2] + grid[i - 1][j - 1] + grid[i - 1][j] == # second row
                    grid[i][j - 2] + grid[i][j - 1] + grid[i][j] == # third row
                    grid[i - 2][j - 2] + grid[i - 1][j - 2] + grid[i][j - 2] == # first col
                    grid[i - 2][j - 1] + grid[i - 1][j - 1] + grid[i][j - 1] == # second col
                    grid[i - 2][j] + grid[i - 1][j] + grid[i][j] == # third col
                    grid[i - 2][j - 2] + grid[i - 1][j - 1] + grid[i][j] == # diagonal
                    grid[i][j - 2] + grid[i - 1][j - 1] + grid[i - 2][j] # other
                )
        return ans