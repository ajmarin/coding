MOVES = ((0, 1), (0, -1), (1, 0), (-1, 0))


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        N = len(grid)
        q = [(grid[0][0], (0, 0))]
        cost = [[inf] * N for _ in range(N)]
        cost[0][0] = grid[0][0]
        while q:
            h, (x, y) = heappop(q)
            for dx, dy in MOVES:
                nx, ny = x + dx, y + dy
                if nx < 0 or nx >= N or ny < 0 or ny >= N:
                    continue
                if h >= cost[nx][ny]:
                    continue
                nh = cost[nx][ny] = h if h > grid[nx][ny] else grid[nx][ny]
                if nx == ny == N - 1:
                    return nh
                heappush(q, (nh, (nx, ny)))
        return grid[0][0]

