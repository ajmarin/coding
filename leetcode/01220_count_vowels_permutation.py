class Solution:
    def countVowelPermutation(self, n: int) -> int:
        MOD = 1000000007
        dp = [[0] * 5 for i in range(n)]
        for i in range(5):
            dp[0][i] = 1
        for i in range(1, n):
            p = i - 1
            # a can come after e, i, u
            dp[i][0] = dp[p][1] + dp[p][2] + dp[p][4]
            # e can come after a, i
            dp[i][1] = dp[p][0] + dp[p][2]
            # i can come after e, o
            dp[i][2] = dp[p][1] + dp[p][3]
            # o can come after i
            dp[i][3] = dp[p][2]
            # u can come after i, o
            dp[i][4] = dp[p][2] + dp[p][3]
            for j in range(5):
                dp[i][j] %= MOD
        return sum(dp[n - 1][i] for i in range(5)) % MOD