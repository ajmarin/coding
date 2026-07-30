class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        counts = [0] * 128
        for c in s:
            counts[ord(c)] += 1
        return (
            "".join(c for c in s if c not in (x, y))
            + y * counts[ord(y)]
            + x * counts[ord(x)]
        )
