DIRS = ((-1, 0), (0, -1), (1, 0), (0, 1))


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        visited = set()

        def dfs(r, c) -> int:
            count = 1
            visited.add((r, c))
            for dr, dc in DIRS:
                nr, nc = r + dr, c + dc
                if nr < 0 or nr >= rows or nc < 0 or nc >= cols:
                    continue
                if (nr, nc) in visited or not grid[nr][nc]:
                    continue
                count += dfs(nr, nc)
            return count

        ans = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] and (i, j) not in visited:
                    ans = max(ans, dfs(i, j))
        return ans
