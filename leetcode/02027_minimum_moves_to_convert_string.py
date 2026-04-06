class Solution:
    def minimumMoves(self, s: str) -> int:
        ans, converted = 0, -1
        for i, c in enumerate(s):
            if c == "X" and converted < i:
                converted = i + 2
                ans += 1
        return ans
