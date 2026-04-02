class Solution:
    def maxPower(self, s: str) -> int:
        best, prev, start = 0, -1, 0
        for i, c in enumerate(s):
            if c != prev:
                best = max(i - start, best)
                start = i
                prev = c
        return max(best, len(s) - start)
