class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum(pat in word for pat in patterns)
