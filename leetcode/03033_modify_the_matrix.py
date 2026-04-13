class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        cols = len(matrix[0])
        col_max = {}

        for row in matrix:
            for j in range(cols):
                if row[j] == -1:
                    if j not in col_max:
                        row[j] = col_max[j] = max(row[j] for row in matrix)
                    else:
                        row[j] = col_max[j]
        return matrix
