class Solution:
    def makeFancyString(self, s: str) -> str:
        a, b = -1, -1
        ans = ""
        for c in s:
            if not a == b == c:
                ans += c
            a, b = b, c
        return ans

