class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows = len(matrix)
        if not rows:
            return
        cols = len(matrix[0])
        fcz = 0
        for i in range(rows):
            if matrix[i][0] == 0:
                fcz = 1
            for j in range(1, cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        for i in range(rows - 1, -1, -1):
            for j in range(cols - 1, 0, -1):
                matrix[i][j] *= 1 - (matrix[i][0] == 0 or matrix[0][j] == 0)
            matrix[i][0] *= 1 - fcz