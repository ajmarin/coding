class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        moves = ((0, 1), (0, -1), (1, 0), (-1, 0))
        rows, cols = len(heightMap), len(heightMap[0])
        boundary = []

        for r in range(rows):
            heappush(boundary, (heightMap[r][0], r, 0))
            heappush(boundary, (heightMap[r][-1], r, cols - 1))
            heightMap[r][0] = heightMap[r][-1] = -1
        for c in range(cols):
            heappush(boundary, (heightMap[0][c], 0, c))
            heappush(boundary, (heightMap[-1][c], rows - 1, c))
            heightMap[0][c] = heightMap[-1][c] = -1

        trapped = 0
        while boundary:
            height, r, c = heappop(boundary)
            for dr, dc in moves:
                nr, nc = r + dr, c + dc
                if dr and (nr < 0 or nr >= rows):
                    continue
                if dc and (nc < 0 or nc >= cols):
                    continue
                neighbor_height = heightMap[nr][nc]
                if neighbor_height == -1:
                    continue
                if neighbor_height < height:
                    trapped += height - neighbor_height
                    neighbor_height = height
                heappush(boundary, (neighbor_height, nr, nc))
                heightMap[nr][nc] = -1
        return trapped
