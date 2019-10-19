class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        if not rows:
            return False
        cols = len(matrix[0])
        left, right = 0, rows * cols
        while left < right:
            mid = (left + right) >> 1
            row = mid // cols
            col = mid % cols
            if matrix[row][col] < target:
                left = mid + 1
            else:
                right = mid
        if left == rows * cols:
            return False
        return matrix[left // cols][left % cols] == target