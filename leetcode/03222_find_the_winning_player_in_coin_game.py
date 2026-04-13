class Solution:
    def winningPlayer(self, x: int, y: int) -> str:
        return "Alice" if min(x, y >> 2) & 1 else "Bob"
