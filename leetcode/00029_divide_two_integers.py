class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        result, to_add = 0, 1
        a, b = abs(dividend), abs(divisor)
        big_div = b
        while (big_div << 1) <= a:
            big_div = big_div << 1
            to_add = to_add << 1
        while big_div >= b:
            if big_div <= a:
                result += to_add
                a -= big_div
            big_div = big_div >> 1
            to_add = to_add >> 1
        if (dividend < 0)^(divisor < 0):
            result = -result
        return result if -2**31 <= result and result <= 2**31 - 1 else 2**31 - 1