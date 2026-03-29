class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        prev = -1
        while n:
            curr = n & 1
            if curr == prev:
                return False
            n >>= 1
            prev = curr
        return True
