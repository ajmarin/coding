class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        MOD = 10**9 + 7
        dx_dy = ((1, 0), (0, 1), (-1, 0), (0, -1))
        dp = [[[0] * n for _ in range(m)] for _ in (1, 2)]
        dp[0][i][j] = 1
        out_of_grid = 0
        for move in range(1, N+1):
            c = dp[move & 1]
            p = dp[1 ^ (move & 1)]
            for x in range(m):
                for y in range(n):
                    c[x][y] = 0
                    for dx, dy in dx_dy:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < m and 0 <= ny < n:
                            c[x][y] += p[nx][ny]
                        else:
                            out_of_grid += p[x][y]
                    c[x][y] %= MOD
                out_of_grid %= MOD
        return out_of_grid