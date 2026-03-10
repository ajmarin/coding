MOD = 10**9 + 7


class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        dp0 = [[0] * (one + 1) for _ in range(zero + 1)]
        dp1 = [[0] * (one + 1) for _ in range(zero + 1)]

        for z in range(1, min(limit, zero) + 1):
            dp0[z][0] = 1
        for o in range(1, min(limit, one) + 1):
            dp1[0][o] = 1

        L = limit + 1

        for z in range(1, zero + 1):
            for o in range(1, one + 1):
                dp0[z][o] = (
                    dp0[z - 1][o] + dp1[z - 1][o] - (0 if z < L else dp1[z - L][o])
                ) % MOD
                dp1[z][o] = (
                    dp0[z][o - 1] + dp1[z][o - 1] - (0 if o < L else dp0[z][o - L])
                ) % MOD

        return (dp0[zero][one] + dp1[zero][one]) % MOD
