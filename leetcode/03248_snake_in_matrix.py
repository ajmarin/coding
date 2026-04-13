class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        i, j = 0, 0
        for c in commands:
            if c == "UP":
                i -= 1
            elif c == "DOWN":
                i += 1
            elif c == "LEFT":
                j -= 1
            else:
                j += 1
        return i * n + j
