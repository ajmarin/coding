class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        has0 = "0" in s and s.index("0")
        return not (has0 and "1" in s[has0:])
