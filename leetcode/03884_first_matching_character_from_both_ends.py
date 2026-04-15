class Solution:
    def firstMatchingIndex(self, s: str) -> int:
        return next((i for i in range(1 + len(s) // 2) if s[i] == s[~i]), -1)
