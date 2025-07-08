class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        ans = prev0 = size = 0
        prev = s[0]
        for i, c in enumerate(s + "2"):
            if c == prev: size += 1
            else:
                if prev == '0':
                    if prev0:
                        total = prev0 + size
                        ans = total if total > ans else ans
                    prev0 = size
                size = 1
            prev = c
        return ans + s.count("1")

