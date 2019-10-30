class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        best = [[10**6] * n for _ in range(n)]
        pq = []
        heapq.heappush(pq, (0, 0, 0))
        best[0][0] = 0
        while pq:
            cost, i, j = heapq.heappop(pq)
            cost = max(cost, grid[i][j])
            if i == j == n - 1:
                return cost
            for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= n or nj < 0 or nj >= n:
                    continue
                if cost < best[ni][nj]:
                    best[ni][nj] = cost
                    heapq.heappush(pq, (cost, ni, nj))