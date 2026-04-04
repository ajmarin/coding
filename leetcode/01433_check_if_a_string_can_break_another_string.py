class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        s1 = sorted(s1)
        s2 = sorted(s2)
        return all(c1 >= c2 for c1, c2 in zip(s1, s2)) or all(
            c1 <= c2 for c1, c2 in zip(s1, s2)
        )
