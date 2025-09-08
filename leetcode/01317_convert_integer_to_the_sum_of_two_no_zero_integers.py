def valid(n):
    while n:
        if n % 10 == 0: return False
        n //= 10
    return True

class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        return next([a, b] for a in range(1, n) if valid(a) and valid(b := n - a)

