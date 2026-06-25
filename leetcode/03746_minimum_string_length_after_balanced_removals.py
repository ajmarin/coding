class Solution:
    def minLengthAfterRemovals(self, s: str) -> int:
        cnt = 0
        for c in s:
            cnt += 1 if c == "a" else -1
        return abs(cnt)
