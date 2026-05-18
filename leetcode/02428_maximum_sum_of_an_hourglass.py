class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        p = [[0] * (cols + 1) for _ in range(rows + 1)]
        prev = p[0]
        for r, row in enumerate(grid):
            curr = p[r + 1]
            for c in range(cols):
                curr[c + 1] = grid[r][c] + prev[c + 1] + curr[c] - prev[c]
            prev = curr

        ans = 0
        for r in range(3, rows + 1):
            pr = p[r]
            pr3 = p[r - 3]
            subr = grid[r - 2]
            for c in range(3, cols + 1):
                total = pr[c] - subr[c - 1] - subr[c - 3]
                total += pr3[c - 3] - pr3[c]
                total -= pr[c - 3]
                ans = total if total > ans else ans
        return ans
