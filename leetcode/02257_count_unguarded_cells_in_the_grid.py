GUARDED = 1
GUARD = 2
WALL = 3


class Solution:
    def countUnguarded(
        self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]
    ) -> int:
        b = [[0] * n for _ in range(m)]
        for x, y in guards:
            b[x][y] = GUARD
        for x, y in walls:
            b[x][y] = WALL
        for x, y in guards:
            for nx in range(x + 1, m, 1):
                if b[nx][y] > GUARDED:
                    break
                b[nx][y] = GUARDED
            for nx in range(x - 1, -1, -1):
                if b[nx][y] > GUARDED:
                    break
                b[nx][y] = GUARDED
            for ny in range(y + 1, n, 1):
                if b[x][ny] > GUARDED:
                    break
                b[x][ny] = GUARDED
            for ny in range(y - 1, -1, -1):
                if b[x][ny] > GUARDED:
                    break
                b[x][ny] = GUARDED
        return sum(row.count(0) for row in b)
