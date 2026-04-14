def digit_product(n: int) -> int:
    res = 1
    while n:
        res *= n % 10
        n //= 10
    return res


class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        return next(x for x in range(n, n + 10) if digit_product(x) % t == 0)
