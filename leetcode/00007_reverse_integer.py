class Solution:
    def reverse(self, x: int) -> int:
        negative = x < 0
        x = -x if negative else x
        res = 0
        while x:
            res = res * 10 + (x % 10)
            x = x // 10
        res = -res if negative else res
        return res if -2**31 <= res and res <= 2**31 - 1 else 0