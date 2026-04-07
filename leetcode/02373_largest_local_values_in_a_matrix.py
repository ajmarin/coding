class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = []
        for i in range(n - 2):
            row = []
            for j in range(n - 2):
                row.append(
                    max(grid[i + di][j + dj] for di, dj in product(range(3), range(3)))
                )
            ans.append(row)
        return ans
