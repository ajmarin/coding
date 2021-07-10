from collections import Counter

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        diff = Counter(t) - Counter(s)
        return next(iter(diff))
