class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        rows, cols = len(coins), len(coins[0])
        prev = [[-inf] * 3 for _ in range(cols)]
        curr = [[-inf] * 3 for _ in range(cols)]
        prev[0][0] = 0
        for r in range(rows):
            for c in range(cols):
                profit = coins[r][c]
                cell = curr[c]
                for n in range(3):
                    cell[n] = profit + max(prev[c][n], curr[c - 1][n] if c else -inf)
                if profit < 0:
                    cell[2] = max(cell[2], cell[1] - profit)
                    cell[1] = max(cell[1], cell[0] - profit)
            prev, curr = curr, prev
        return max(prev[-1])
