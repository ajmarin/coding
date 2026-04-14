class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        digits = [10] * 4
        for n in (num1, num2, num3):
            for d in range(3, -1, -1):
                digits[d] = min(digits[d], n % 10)
                n //= 10
        return 1000 * digits[0] + 100 * digits[1] + 10 * digits[2] + digits[3]
