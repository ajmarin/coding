DIRS = ((-1, 1), (1, 1), (1, -1), (-1, -1))
W = [2, 2, 0]

class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        @cache
        def dfs(x, y, d, turn, w):
            if not (0 <= x < rows and 0 <= y < cols) or grid[x][y] != w:
                return 0
            dx, dy = DIRS[d]
            res = dfs(x + dx, y + dy, d, turn, W[w])
            if not turn:
                nd = (d + 1) % 4
                dx, dy = DIRS[nd]
                cand = dfs(x + dx, y + dy, nd, True, W[w])
                res = cand if cand > res else res
            return 1 + res

        ans = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] != 1: continue
                for d in range(4):
                    cand = dfs(r, c, d, False, 1)
                    ans = cand if cand > ans else ans
        return ans

