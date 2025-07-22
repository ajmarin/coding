MOD = 10**9 + 7

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        if k > len(word): return 0
        freqs = [len([*g]) for _, g in groupby(word)]
        total = 1
        for f in freqs: total = total * f % MOD
        if len(freqs) >= k: return total

        curr, prev = [0] * k, [1] * k
        for fi in freqs:
            fi += 1
            curr[0] = 0
            for j in range(1, min(fi, k)): curr[j] = prev[j - 1]
            for j in range(fi, k): curr[j] = prev[j - 1] - prev[j - fi]
            prev = list(accumulate(curr))
        return (total - prev[k - 1]) % MOD

