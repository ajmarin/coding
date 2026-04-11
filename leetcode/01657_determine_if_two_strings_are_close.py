class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        c1, c2 = Counter(word1), Counter(word2)
        return c1 == c2 or (
            c1.keys() == c2.keys() and sorted(c1.values()) == sorted(c2.values())
        )
