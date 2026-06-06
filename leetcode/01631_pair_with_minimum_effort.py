class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows, cols = len(heights), len(heights[0])
        tr, tc = rows - 1, cols - 1

        effort = [[10**6] * cols for _ in range(rows)]
        pq = [(0, tr + tc, 0, 0)]
        while pq:
            e, _, r, c = heappop(pq)
            if e > effort[r][c]:
                continue
            if r == tr and c == tc:
                return e

            h = heights[r][c]
            for dr, dc in pairwise((0, 1, 0, -1, 0)):
                nr = r + dr
                if nr < 0 or nr >= rows:
                    continue
                nc = c + dc
                if nc < 0 or nc >= cols:
                    continue
                diff = abs(heights[nr][nc] - h)
                cand = diff if diff > e else e
                if cand < effort[nr][nc]:
                    effort[nr][nc] = cand
                    heappush(pq, (cand, tr - nr + tc - nc, nr, nc))
