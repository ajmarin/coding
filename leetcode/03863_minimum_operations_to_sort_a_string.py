class Solution:
    def minOperations(self, s: str) -> int:
        if all(c1 <= c2 for c1, c2 in pairwise(s)):
            return 0
        low, high = min(s), max(s)
        if low == s[0] or high == s[-1]:
            return 1
        if len(s) == 2 and s[0] > s[1]:
            return -1
        return 2 + (
            s[-1] == low and s.count(low) == 1 and s[0] == high and s.count(high) == 1
        )
