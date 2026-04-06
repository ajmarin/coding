PRIMES = [2, 3]

for n in range(5, 101, 2):
    if all(n % p != 0 for p in PRIMES):
        PRIMES.append(n)


class Solution:
    def isThree(self, n: int) -> bool:
        for p in PRIMES:
            if p * p > n:
                return False
            if n % p == 0 and p == n // p:
                return True
        return False
