class Solution:
    def minTimeToType(self, word: str) -> int:
        ans, pointer = len(word), ord("a")
        for c in word:
            c = ord(c)
            if c == pointer:
                continue
            dist = abs(c - pointer)
            ans += min(dist, 26 - dist)
            pointer = c
        return ans
