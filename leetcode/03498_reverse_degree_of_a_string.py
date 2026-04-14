class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum((26 + ord("a") - ord(c)) * index for index, c in enumerate(s, 1))
