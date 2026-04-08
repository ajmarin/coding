class Solution:
    def alternateDigitSum(self, n: int) -> int:
        digits = res = 0
        sign = 1
        while n:
            digits += 1
            res += sign * (n % 10)
            sign = -sign
            n //= 10
        return res if digits & 1 else -res
