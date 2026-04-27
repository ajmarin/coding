UP, RIGHT, DOWN, LEFT = (-1, 0), (0, 1), (1, 0), (0, -1)
DIRECTIONS = {
    1: (LEFT, RIGHT),
    2: (UP, DOWN),
    3: (LEFT, DOWN),
    4: (RIGHT, DOWN),
    5: (UP, LEFT),
    6: (UP, RIGHT),
}


class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        rows, cols = len(grid), len(grid[0])
        visited = set()

        def dfs(r, c):
            visited.add((r, c))
            for dr, dc in DIRECTIONS[grid[r][c]]:
                nr = r + dr
                if nr < 0 or nr >= rows:
                    continue
                nc = c + dc
                if nc < 0 or nc >= cols:
                    continue
                if (nr, nc) in visited or (-dr, -dc) not in DIRECTIONS[grid[nr][nc]]:
                    continue
                dfs(nr, nc)

        dfs(0, 0)
        return (rows - 1, cols - 1) in visited
