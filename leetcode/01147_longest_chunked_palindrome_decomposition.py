class Solution:
    def longestDecomposition(self, text: str) -> int:
        n = len(text)
        for i in range(1, 1 + (n >> 1)):
            if text[:i] == text[n - i:]:
                return 2 + self.longestDecomposition(text[i:n-i])
        return 1 if text else 0