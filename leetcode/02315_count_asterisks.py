class Solution:
    def countAsterisks(self, s: str) -> int:
        ans, include = 0, True
        for c in s:
            if c == "|":
                include = not include
                continue
            if include:
                ans += c == "*"
        return ans
