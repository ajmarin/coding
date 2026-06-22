MOVES = list(pairwise((0, 1, 0, -1, 0)))


class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        rows, cols = len(isWater), len(isWater[0])
        q = deque([])
        for r, row in enumerate(isWater):
            for c, val in enumerate(row):
                if val == 1:
                    q.append((r, c, 0))
                    row[c] = 0
                else:
                    row[c] = -1
        while q:
            r, c, h = q.popleft()
            h += 1
            for dr, dc in MOVES:
                nr = r + dr
                if nr < 0 or nr >= rows:
                    continue
                nc = c + dc
                if nc < 0 or nc >= cols or isWater[nr][nc] >= 0:
                    continue
                isWater[nr][nc] = h
                q.append((nr, nc, h))
        return isWater
