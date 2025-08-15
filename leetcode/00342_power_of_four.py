class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n == 0: return False
        while not n & 3:
            n >>= 2
        return n == 1

