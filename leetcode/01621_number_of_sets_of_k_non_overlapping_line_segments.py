class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        return comb(n + k - 1, k << 1) % 1_000_000_007
