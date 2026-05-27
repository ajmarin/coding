DIRS = ((0, 1), (1, 0), (0, -1), (-1, 0))


class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        if grid[0][0] or grid[-1][-1]:
            return 0

        n = len(grid)

        def neighbors(r: int, c: int, f):
            for dr, dc in DIRS:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and f(grid[nr][nc]):
                    yield nr, nc

        q = deque([])
        for r, row in enumerate(grid):
            for c in range(n):
                if row[c]:
                    row[c] = 0
                    q.append((r, c))
                else:
                    row[c] = 1000

        while q:
            r, c = q.popleft()
            d = grid[r][c] + 1
            for nr, nc in neighbors(r, c, lambda x: x > d):
                grid[nr][nc] = d
                q.append((nr, nc))

        q.append((grid[0][0], 0, 0))
        grid[0][0] = -1
        not_visited = lambda x: x != -1
        while q:
            s, r, c = q.popleft()
            if r == c == n - 1:
                return s
            for nr, nc in neighbors(r, c, not_visited):
                news = min(s, grid[nr][nc])
                grid[nr][nc] = -1
                if news < s:
                    q.append((news, nr, nc))
                else:
                    q.appendleft((news, nr, nc))
