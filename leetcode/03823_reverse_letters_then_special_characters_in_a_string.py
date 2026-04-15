class Solution:
    def reverseByType(self, s: str) -> str:
        letters = [c for c in s if c.isalpha()]
        symbols = [c for c in s if not c.isalpha()]
        return "".join(letters.pop() if c.isalpha() else symbols.pop() for c in s)
