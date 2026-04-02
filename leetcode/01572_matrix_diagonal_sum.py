class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        primary = sum(mat[i][i] for i in range(n))
        secondary = sum(mat[i][~i] for i in range(n))
        return primary + secondary - (mat[n // 2][n // 2] if n & 1 else 0)
