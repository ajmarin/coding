class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        pos = dict((c, idx) for idx, c in enumerate(s))
        return sum(abs(pos[c] - idx) for idx, c in enumerate(t))
