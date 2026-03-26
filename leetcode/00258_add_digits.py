class Solution:
    def addDigits(self, num: int) -> int:
        return (num > 0) * (1 + (num - 1) % 9)
