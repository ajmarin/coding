class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        visited = [[False for _ in range(cols)] for _ in grid]
        def dfs(i: int, j: int):
            closed = True
            visited[i][j] = True
            for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= rows or nj < 0 or nj >= cols:
                    closed = False
                elif grid[ni][nj] == 0 and not visited[ni][nj]:
                    closed &= dfs(ni, nj)
            return closed
        closed_islands = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0 and not visited[i][j]:
                    closed_islands += dfs(i, j)
        return closed_islands