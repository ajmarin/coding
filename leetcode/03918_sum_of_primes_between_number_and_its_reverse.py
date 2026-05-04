PRIMES = [2, 3]


def is_prime(n: int) -> bool:
    for p in PRIMES:
        if n % p == 0:
            return False
        if p * p > n:
            return True


for i in range(5, 1001, 2):
    if is_prime(i):
        PRIMES.append(i)
PRIME_SUM = [0] + list(accumulate(PRIMES))


class Solution:
    def sumOfPrimesInRange(self, n: int) -> int:
        rev = int(str(n)[::-1])
        start, end = min(n, rev), max(n, rev)
        si = bisect_left(PRIMES, start)
        ei = bisect_right(PRIMES, end)
        return PRIME_SUM[ei] - PRIME_SUM[si]
