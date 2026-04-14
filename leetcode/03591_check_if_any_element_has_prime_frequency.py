PRIMES = [2, 3, 5, 7]


def is_prime(n: int) -> int:
    return n > 1 and (n in PRIMES or all(n % p != 0 for p in PRIMES))


class Solution:
    def checkPrimeFrequency(self, nums: List[int]) -> bool:
        return any(is_prime(v) for v in Counter(nums).values())
