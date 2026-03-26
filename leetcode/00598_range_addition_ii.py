class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        min_row = m
        min_col = n
        for row, col in ops:
            min_row = row if row < min_row else min_row
            min_col = col if col < min_col else min_col
        return min_row * min_col
