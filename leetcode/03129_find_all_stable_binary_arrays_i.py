MOD = 10**9 + 7


class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        # dp0[z][o] -> having z 0s and o 1s, ending in 0
        dp0 = [[0] * (one + 1) for _ in range(zero + 1)]
        # dp1[z][o] -> having z 0s and o 1s, ending in 1
        dp1 = [[0] * (one + 1) for _ in range(zero + 1)]

        for z in range(1, min(zero, limit) + 1):
            dp0[z][0] = 1
        for o in range(1, min(one, limit) + 1):
            dp1[0][o] = 1

        for z in range(1, zero + 1):
            for o in range(1, one + 1):
                dp0[z][o] = (
                    sum(dp1[z - i][o] for i in range(1, min(limit, z) + 1)) % MOD
                )
                dp1[z][o] = (
                    sum(dp0[z][o - i] for i in range(1, min(limit, o) + 1)) % MOD
                )

        return (dp0[zero][one] + dp1[zero][one]) % MOD
