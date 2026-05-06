class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        for row in grid:
            if not row[0]:
                for c in range(cols):
                    row[c] = 1 - row[c]
        ans = 0
        bit_value = 1 << (cols - 1)
        for c in range(cols):
            ones = sum(grid[r][c] for r in range(rows))
            ans += bit_value * max(ones, rows - ones)
            bit_value >>= 1
        return ans
