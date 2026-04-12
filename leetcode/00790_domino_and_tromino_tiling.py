DP = [1, 1, 2]
MOD = 10**9 + 7


prev = DP[-1]
for i in range(3, 1001):
    prev = (DP[i - 3] + (prev << 1)) % MOD
    DP.append(prev)


class Solution:
    def numTilings(self, n: int) -> int:
        return DP[n]
