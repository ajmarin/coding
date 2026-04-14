class Solution:
    def findValidPair(self, s: str) -> str:
        c = Counter(s)
        return next(
            (
                d1 + d2
                for d1, d2 in pairwise(s)
                if d1 != d2 and c[d1] == int(d1) and c[d2] == int(d2)
            ),
            "",
        )
