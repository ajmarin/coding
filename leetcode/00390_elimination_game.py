class Solution:
    def lastRemaining(self, n: int, winner=1, step=1, right=True) -> int:
        if n == 1:
            return winner
        return self.lastRemaining(
            n >> 1, winner + (step & -(right or n & 1)), step * 2, 1 - right
        )
