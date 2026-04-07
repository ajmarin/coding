class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        ans = 0
        while start or goal:
            ans += start & 1 != goal & 1
            start >>= 1
            goal >>= 1
        return ans
