class Solution:
    def __init__(self):
        self.start = 1000
        self.length = 0

    def longestNiceSubstring(self, s: str, start=0) -> str:
        l = len(s)
        if l < self.length or (l == self.length and start > self.start):
            return
        cnt = Counter(s)
        for i, c in enumerate(s):
            if not cnt[c.swapcase()]:
                self.longestNiceSubstring(s[:i], start)
                self.longestNiceSubstring(s[i + 1 :], start + i + 1)
                break
        else:
            self.start = start
            self.length = l
        return s[self.start : self.start + self.length]
