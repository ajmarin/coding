class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0] * n for i in range(n)]
        dxdy = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        pos = [0, -1]
        current = 1
        d = 0
        row, col = n, n - 1
        while row:
            for i in range(row):
                pos[0] += dxdy[d][0]
                pos[1] += dxdy[d][1]
                matrix[pos[0]][pos[1]] = current
                current += 1
            row -= 1
            row, col = col, row
            d = (d + 1) % 4
        return matrix