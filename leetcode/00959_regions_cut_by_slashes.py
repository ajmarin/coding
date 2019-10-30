class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        TOP = 1
        BOTTOM = 2
        BOTH = 3
        DOWN, RIGHT, UP, LEFT = range(4)
        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))
        rows, cols = len(grid), len(grid[0])
        visited = [[0] * cols for _ in grid]
        def dfs(i: int, j: int, pos_mask: int):
            d = [DOWN, RIGHT, UP, LEFT]
            if pos_mask == TOP:
                if grid[i][j] == '/':
                    d = [UP, LEFT]
                else:
                    d = [UP, RIGHT]
            elif pos_mask == BOTTOM:
                if grid[i][j] == '/':
                    d = [DOWN, RIGHT]
                else:
                    d = [DOWN, LEFT]
            for didx in d:
                di, dj = directions[didx]
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= rows or nj < 0 or nj >= rows:
                    continue
                if grid[ni][nj] == ' ':
                    mask = BOTH
                elif grid[ni][nj] == '/':
                    if didx in (DOWN, RIGHT):
                        mask = TOP
                    else:
                        mask = BOTTOM
                else:
                    if didx in (DOWN, LEFT):
                        mask = TOP
                    else:
                        mask = BOTTOM
                if not visited[ni][nj] & mask:
                    visited[ni][nj] |= mask
                    dfs(ni, nj, mask)
        regions = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == ' ' and visited[i][j] != BOTH:
                    regions += 1
                    visited[i][j] = BOTH
                    dfs(i, j, BOTH)
                else:
                    for mask in (BOTTOM, TOP):
                        if not visited[i][j] & mask:
                            regions += 1
                            visited[i][j] |= mask
                            dfs(i, j, mask)
        return regions