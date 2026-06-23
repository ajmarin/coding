MOD = 10**9 + 7


class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        sz = r - l + 1
        dp = [[[1] * sz, [1] * sz] for _ in range(2)]
        prev_up, prev_down = [1] * sz, [1] * sz
        suff = sz
        for z in range(n - 1):
            up, down = dp[z & 1]
            pref = 0
            for i in range(sz):
                suff = (suff - prev_up[i]) % MOD
                down[i] = suff

                up[i] = pref
                pref = (pref + prev_down[i]) % MOD
            suff = sum(up) % MOD
            prev_up, prev_down = up, down
        return (suff + sum(prev_down)) % MOD
