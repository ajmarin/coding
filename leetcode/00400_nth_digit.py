class Solution:
    def findNthDigit(self, n: int) -> int:
        nums, digits = 9, 1
        while n > nums * digits:
            n -= nums * digits
            nums *= 10
            digits += 1
        digit = (n - 1) % digits
        num = 10 ** (digits - 1) + (n - 1) // digits
        return int(str(num)[digit])
