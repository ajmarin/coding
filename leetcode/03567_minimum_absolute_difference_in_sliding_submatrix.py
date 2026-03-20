class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        def compute_mindiff(r, c):
            numbers = set(
                grid[i][j] for i, j in product(range(r, r + k), range(c, c + k))
            )
            if len(numbers) == 1:
                return 0
            mindiff, prev = 10**6, -(10**6)
            for num in sorted(numbers):
                diff = num - prev
                mindiff = diff if diff < mindiff else mindiff
                prev = num
            return mindiff

        if k == 1:
            compute_mindiff = lambda r, c: 0

        rows, cols = len(grid), len(grid[0])
        ans = []
        for i in range(rows - k + 1):
            row = []
            for j in range(cols - k + 1):
                row.append(compute_mindiff(i, j))
            ans.append(row)
        return ans
