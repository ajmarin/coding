class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        rows, cols = len(grid), len(grid[0])
        visited = set()

        def bfs(r, c):
            q = deque([(r, c)])
            total = 0
            while q:
                r, c = q.popleft()
                total += grid[r][c]
                for dr, dc in ((0, -1), (0, 1), (1, 0), (-1, 0)):
                    nr, nc = r + dr, c + dc
                    if (nr, nc) in visited: continue
                    if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc]:
                        visited.add((nr, nc))
                        q.append((nr, nc))
            return total

        ans = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] and (r, c) not in visited:
                    visited.add((r, c))
                    ans += bfs(r, c) % k == 0
        return ans

