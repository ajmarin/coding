class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 10**9 + 7
        return pow(20, n >> 1, MOD) * (5 if n & 1 else 1) % MOD
