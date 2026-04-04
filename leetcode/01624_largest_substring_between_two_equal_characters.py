class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        l = len(s)
        for gap in range(l - 1, -1, -1):
            for start in range(l - gap):
                if s[start] == s[start + gap]:
                    return gap - 1
        return -1
