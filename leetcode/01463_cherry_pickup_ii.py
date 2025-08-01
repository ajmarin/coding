class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        dp = [[[-inf] * cols for _ in range(cols)] for _ in range(2)]
        curr, prev = dp[1], dp[0]
        prev[0][-1] = grid[0][0] + grid[0][-1]
        moves = [slice(max(i - 1, 0), min(i + 2, cols)) for i in range(cols)]
        for row in range(1, rows):
            for c1 in range(cols):
                for c2 in range(c1 + 1, cols):
                    curr[c1][c2] = grid[row][c1] + grid[row][c2] + max(
                        max(prevc1[moves[c2]])
                        for prevc1 in prev[moves[c1]]
                    )
            curr, prev = prev, curr
        return max(max(prev, key=max))

