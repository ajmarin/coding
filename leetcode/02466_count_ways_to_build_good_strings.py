class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = 10**9 + 7

        offset = max(zero, one)
        dp = [0] * offset + [1] + [0] * high

        for i in range(offset + 1, len(dp)):
            dp[i] = (dp[i - zero] + dp[i - one]) % MOD

        return sum(dp[low + offset :]) % MOD
