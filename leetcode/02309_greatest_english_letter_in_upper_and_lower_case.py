class Solution:
    def greatestLetter(self, s: str) -> str:
        return next(
            (c for c in string.ascii_uppercase[::-1] if c in s and c.lower() in s), ""
        )
