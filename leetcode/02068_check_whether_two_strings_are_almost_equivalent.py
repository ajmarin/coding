class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        c1, c2 = Counter(word1), Counter(word2)
        return all(abs(c1[c] - c2[c]) < 4 for c in chain(c1.keys(), c2.keys()))
