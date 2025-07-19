def popcount_depth(n):
    depth = 0
    while n > 1:
        n = n.bit_count()
        depth += 1
    return depth

DMAP = {i: popcount_depth(i) for i in range(100)}

class Solution:
    def popcountDepth(self, n: int, k: int) -> int:
        if k == 0: return 1
        max_bits = n.bit_length()
        max_n_bin = [*map(int, bin(n)[2:])]

        @cache
        def dp(pos, rem_ones, cap):
            if rem_ones < 0: return 0
            if pos == len(max_n_bin): return rem_ones == 0

            limit = max_n_bin[pos] if cap else 1
            res = 0
            for d in range(0, limit + 1):
                res += dp(pos + 1, rem_ones - d, cap and d == limit)
            return res


        ans = 0
        for o in range(1, max_bits + 1):
            if DMAP[o] == k - 1:
                ans += dp(0, o, True)
        return ans - (k == 1)

