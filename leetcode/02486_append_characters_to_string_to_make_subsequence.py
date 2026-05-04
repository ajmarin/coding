class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        pos, expected = 0, t[0]
        lent = len(t)
        t += "_"
        for c in s:
            if c == t[pos]:
                expected = t[pos := pos + 1]
                if pos == lent:
                    break
        return lent - pos
