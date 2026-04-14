class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        prev = grid[0]
        ans = 0
        for row in grid[1:]:
            for j, n in enumerate(row):
                if n <= prev[j]:
                    add = prev[j] - n + 1
                    ans += add
                    row[j] += add
            prev = row
        return ans
