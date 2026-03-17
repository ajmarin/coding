class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        ans, prev = 0, None

        for row in matrix:
            for c in range(cols):
                if prev and row[c]:
                    row[c] += prev[c]
            base, prev = 0, row
            for height in sorted(row, reverse=True):
                base += 1
                area = base * height
                ans = area if area > ans else ans
        return ans
