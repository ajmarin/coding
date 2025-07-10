MOD = 10**9 + 7

class Solution:
    def numWays(self, s: str) -> int:
        one_pos = [i for i, c in enumerate(s) if c == '1']
        if not one_pos:
            n = len(s)
            return (((n - 1) * (n - 2)) >> 1) % MOD

        if len(one_pos) % 3:
            return 0

        t = len(one_pos) // 3
        first_gap = one_pos[t] - one_pos[t - 1]
        second_gap = one_pos[2 * t] - one_pos[2 * t - 1]
        return first_gap * second_gap % MOD

