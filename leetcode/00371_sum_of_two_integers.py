class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        maxv = 0x0fffffff
        while b:
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
        return a if a <= maxv else ~(a ^ mask)