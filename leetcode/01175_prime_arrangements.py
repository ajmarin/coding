MOD = 10**9 + 7
PRIMES = []


for n in range(2, 101):
    if all(n % p != 0 for p in PRIMES):
        PRIMES.append(n)


def factorial(n):
    res = 1
    for n in range(n, 1, -1):
        res = (res * n) % MOD
    return res


class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        prime_count = bisect_right(PRIMES, n)
        return factorial(n - prime_count) * factorial(prime_count) % MOD
