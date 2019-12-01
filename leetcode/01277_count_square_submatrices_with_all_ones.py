class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        squares = 0
        get = lambda i, j: matrix[i][j] if 0 <= i < rows and 0 <= j < cols else 0
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 1:
                    matrix[i][j] += min(get(i - 1, j), get(i, j - 1), get(i - 1, j - 1))
                    squares += matrix[i][j]
        return squares