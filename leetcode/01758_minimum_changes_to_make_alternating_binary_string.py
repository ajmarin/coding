class Solution:
    def minOperations(self, s: str) -> int:
        ans = wanted = 0
        for c in s:
            ans += int(c) != wanted
            wanted = not wanted
        return min(ans, len(s) - ans)
