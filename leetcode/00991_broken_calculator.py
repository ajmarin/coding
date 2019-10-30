class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        steps = 0
        while X < Y:
            steps += 1 + (Y & 1)
            Y = (Y + (Y & 1)) >> 1
        return steps + X - Y