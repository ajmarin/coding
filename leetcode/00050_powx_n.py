class Solution:
    def myPow(self, x: float, n: int) -> float:
        power, absx = abs(n), abs(x)
        res = 1
        while power:
            if power & 1:
                res *= absx
            absx = absx * absx
            power = power >> 1
        if (x < 0) and (n & 1):
            res = -res
        if n < 0:
            res = 1 / res
        return res