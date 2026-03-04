class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows, cols = len(mat), len(mat[0])
        row_sum, col_sum = [0] * rows, [0] * cols

        for i, row in enumerate(mat):
            for j, n in enumerate(row):
                row_sum[i] += n
                col_sum[j] += n

        return sum(
            mat[i][j] == 1 and row_sum[i] == 1 and col_sum[j] == 1
            for i in range(rows)
            for j in range(cols)
        )
