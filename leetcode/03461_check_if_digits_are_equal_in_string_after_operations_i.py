class Solution:
    def hasSameDigits(self, s: str) -> bool:
        d = [int(c) for c in s]
        while len(d) > 2:
            d = [(a + b) % 10 for a, b in pairwise(d)]
        return d[0] == d[1]
