class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        row = rows - 1
        col = 0
        while col < cols:
            x, y = row, col
            while x < rows and y < cols:
                if matrix[x][y] != matrix[row][col]:
                    return False
                x += 1
                y += 1
            if row:
                row -= 1
            else:
                col += 1
        return True