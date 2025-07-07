class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        def dfs(x, y):
            grid[x][y] = 0
            for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                nx, ny = x + dx, y + dy
                if 0 < nx < rows and 0 < ny < cols and grid[nx][ny]:
                    dfs(nx, ny)

        for i in range(rows):
            if grid[i][0] == 1: dfs(i, 0)
            if grid[i][cols - 1] == 1: dfs(i, cols - 1)
        for j in range(1, cols - 1):
            if grid[0][j] == 1: dfs(0, j)
            if grid[rows - 1][j] == 1: dfs(rows - 1, j)

        return sum(map(sum, grid))

