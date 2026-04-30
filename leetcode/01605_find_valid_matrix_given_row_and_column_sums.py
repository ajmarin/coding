class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        rows, cols = len(rowSum), len(colSum)
        grid = [[0] * cols for _ in range(rows)]
        i = j = 0
        while i < rows and j < cols:
            if rowSum[i] <= colSum[j]:
                grid[i][j] = rowSum[i]
                colSum[j] -= rowSum[i]
                i += 1
            else:
                grid[i][j] = colSum[j]
                rowSum[i] -= colSum[j]
                j += 1
        return grid
