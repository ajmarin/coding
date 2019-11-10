class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        matrix = [[0 for _ in range(m)] for _ in range(n)]
        for row, col in indices:
            for j in range(m):
                matrix[row][j] += 1
            for i in range(n):
                matrix[i][col] += 1
        return sum(matrix[i][j] & 1 for i in range(n) for j in range(m))