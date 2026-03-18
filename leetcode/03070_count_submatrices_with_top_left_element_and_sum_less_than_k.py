class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        ans, prev_row = 0, [0] * len(grid[0])
        for row in grid:
            pn = 0
            for i, n in enumerate(row):
                pn = row[i] = n + pn
            for j, (a, b) in enumerate(zip(row, prev_row)):
                row[j] = val = a + b
                ans += val <= k
            prev_row = row
        return ans
