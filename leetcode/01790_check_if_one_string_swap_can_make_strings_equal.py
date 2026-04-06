class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        return Counter(s1) == Counter(s2) and sum(
            c1 != c2 for c1, c2 in zip(s1, s2)
        ) in [0, 2]
