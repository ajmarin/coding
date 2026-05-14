PRIMES = [2, 3]


def is_prime(n):
    for p in PRIMES:
        if p * p > n:
            return True
        if n % p == 0:
            return False


def get_primes():
    for i in range(5, 31_625, 2):
        if is_prime(i):
            PRIMES.append(i)
    return PRIMES


PRIME_SQ = [x * x for x in get_primes()]


class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        return (r - l + 1) - bisect_right(PRIME_SQ, r) + bisect_left(PRIME_SQ, l)
