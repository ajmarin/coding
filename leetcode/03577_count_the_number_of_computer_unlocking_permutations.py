class Solution:
    def countPermutations(self, complexity: List[int]) -> int:
        first = complexity[0]
        if any(c <= first for c in complexity[1:]):
            return 0
        MOD = 10**9 + 7
        ans = 1
        for i in range(1, len(complexity)):
            ans = ans * i % MOD
        return ans
