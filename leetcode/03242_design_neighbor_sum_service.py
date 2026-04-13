class NeighborSum:
    def __init__(self, grid: List[List[int]]):
        self.rows = len(grid)
        self.cols = len(grid[0])
        self.g = grid
        self.pos = {}
        for i in range(self.rows):
            for j in range(self.cols):
                self.pos[grid[i][j]] = (i, j)

    def adjacentSum(self, value: int) -> int:
        r, c = self.pos[value]
        res = 0
        for dr, dc in ((0, 1), (0, -1), (1, 0), (-1, 0)):
            nr, nc = r + dr, c + dc
            if 0 <= nr < self.rows and 0 <= nc < self.cols:
                res += self.g[nr][nc]
        return res

    def diagonalSum(self, value: int) -> int:
        r, c = self.pos[value]
        res = 0
        for dr, dc in ((1, 1), (-1, -1), (1, -1), (-1, 1)):
            nr, nc = r + dr, c + dc
            if 0 <= nr < self.rows and 0 <= nc < self.cols:
                res += self.g[nr][nc]
        return res
