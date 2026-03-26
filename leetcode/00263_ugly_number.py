class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0:
            return False
        for div in [2, 3, 5]:
            while n % div == 0:
                n //= div
        return n == 1
