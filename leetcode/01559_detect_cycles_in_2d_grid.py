class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        rows, cols = len(grid), len(grid[0])

        visited = set()

        def dfs(r, c, pr=None, pc=None):
            if (r, c) in visited:
                return True
            me = grid[r][c]
            visited.add((r, c))
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr, nc = r + dr, c + dc
                if nr < 0 or nr >= rows or nc < 0 or nc >= cols:
                    continue
                if (nr == pr and nc == pc) or grid[nr][nc] != me:
                    continue
                if dfs(nr, nc, r, c):
                    return True
            return False

        return any(
            (r, c) not in visited and dfs(r, c)
            for r in range(rows)
            for c in range(cols)
        )
