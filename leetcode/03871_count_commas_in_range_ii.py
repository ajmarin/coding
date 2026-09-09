CUTOFFS = [10**e - 1 for e in range(3, 16, 3)]


class Solution:
    def countCommas(self, n: int) -> int:
        return sum(n - c for c in CUTOFFS if n > c)
