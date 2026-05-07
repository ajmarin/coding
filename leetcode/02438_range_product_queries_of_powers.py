class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7

        power = 1
        powers = []
        while n:
            if n & 1:
                powers.append(power)
            power <<= 1
            n >>= 1

        @cache
        def solve(l: int, r: int) -> int:
            res = 1
            for i in range(l, r + 1):
                res = res * powers[i] % MOD
            return res

        return [solve(*q) for q in queries]
