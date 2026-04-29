class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        hr, hc = rows >> 1, cols >> 1

        ans = doubles = singles = 0
        for r in range(hr):
            beg, end = grid[r], grid[~r]
            for c in range(hc):
                total = beg[c] + beg[~c] + end[c] + end[~c]
                ans += min(total, 4 - total)
            if cols & 1:
                ones = grid[r][hc] + grid[~r][hc]
                singles += ones == 1
                doubles += ones == 2
        if rows & 1:
            for c in range(hc):
                ones = grid[hr][c] + grid[hr][~c]
                singles += ones == 1
                doubles += ones == 2
            if cols & 1:
                ans += grid[hr][hc]
        return ans + (singles if not doubles & 1 or singles else 2)
