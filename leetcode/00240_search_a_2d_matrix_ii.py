class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix or not matrix[0]:
            return False
        for row in matrix:
            if row[0] > target:
                break
            index = bisect.bisect(row, target)
            if index and row[index - 1] == target:
                return True
        return False