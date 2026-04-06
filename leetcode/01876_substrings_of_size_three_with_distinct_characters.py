class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        return sum(s[i] != s[i + 1] != s[i + 2] != s[i] for i in range(len(s) - 2))
