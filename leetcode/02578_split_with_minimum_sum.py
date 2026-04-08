class Solution:
    def splitNum(self, num: int) -> int:
        num1, num2 = 0, 0
        digits = []
        while num:
            digits.append(num % 10)
            num //= 10
        digits.sort()
        for i, d in enumerate(digits):
            if i & 1:
                num2 = 10 * num2 + d
            else:
                num1 = 10 * num1 + d
        return num1 + num2
