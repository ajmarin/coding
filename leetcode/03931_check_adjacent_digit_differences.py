class Solution:
    def isAdjacentDiffAtMostTwo(self, s: str) -> bool:
        return all(abs(b - a) <= 2 for a, b in pairwise(map(int, s)))
