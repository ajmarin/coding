class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n = len(part)
        while (i := s.find(part)) != -1:
            s = s[:i] + s[i + n:]
        return s

