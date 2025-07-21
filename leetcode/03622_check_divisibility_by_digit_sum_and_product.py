def get_digit_sum_and_prod(n):
    s, p = 0, 1
    while n:
        d = n % 10
        s += d
        p *= d
        n //= 10
    return s, p

class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sumv, prod = get_digit_sum_and_prod(n)
        return n % (sumv + prod) == 0

