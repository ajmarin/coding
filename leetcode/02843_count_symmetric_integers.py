def symmetric(n: int) -> int:
    if n < 100 and n % 11 == 0:
        return True
    return n > 1000 and n // 1000 + n // 100 % 10 == n % 10 + (n % 100) // 10


class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        return sum(map(symmetric, range(low, high + 1)))
