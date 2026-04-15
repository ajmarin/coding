class Solution:
    def residuePrefixes(self, s: str) -> int:
        chars = set()
        ans = 0
        for i, c in enumerate(s, start=1):
            chars.add(c)
            if len(chars) >= 3:
                break
            ans += len(chars) == i % 3
        return ans
