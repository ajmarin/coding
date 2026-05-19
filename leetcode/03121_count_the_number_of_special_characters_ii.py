class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        n = len(word)
        first, last = {}, {}
        for i, c in enumerate(word):
            if "A" <= c <= "Z":
                first.setdefault(c, i)
            else:
                last[c] = i
        return sum(last.get(c.lower(), n) < first[c] for c in first)
