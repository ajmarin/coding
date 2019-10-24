class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        cols = len(matrix[0]) if rows else 0
        maxsq, prev = 0, 0
        dp = [0]*cols
        for i in range(rows):
            for j in range(cols):
                temp = dp[j]
                if matrix[i][j] == '1':
                    dp[j] = min(dp[j - 1] if j else 0, dp[j], prev) + 1
                    maxsq = max(maxsq, dp[j])
                else:
                    dp[j] = 0
                prev = temp
        return maxsq * maxsq