DIRECTIONS = ((-1, 0), (0, -1), (1, 0), (0, 1))


class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        area, n = 0, len(grid)
        for i in range(n):
            for j in range(n):
                height = grid[i][j]
                if height:
                    area += 4 * height + 2  # top and bottom
                    for di, dj in DIRECTIONS:
                        ni, nj = i + di, j + dj
                        if 0 <= ni < n and 0 <= nj < n:
                            area -= min(grid[ni][nj], height)
        return area
