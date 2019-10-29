class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        dx_dy = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        visited = [[grid[x][y] == 0 for y in range(cols)] for x in range(rows)]
        def dfs(x: int, y: int) -> int:
            visited[x][y] = True
            best = 0
            options = []
            for dx, dy in dx_dy:
                nx, ny = x + dx, y + dy
                if nx < 0 or rows <= nx or ny < 0 or cols <= ny:
                    continue
                if visited[nx][ny]:
                    continue
                options.append((grid[nx][ny], nx, ny))
            options.sort(reverse=True)
            for _, nx, ny in options:
                best = max(best, dfs(nx, ny))
            visited[x][y] = False
            return best + grid[x][y]
        return max(dfs(x, y) for x in range(rows) for y in range(cols) if grid[x][y])