PRIMES = {2, 3, 5, 7, 11, 13, 17, 19}


class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        return sum(n.bit_count() in PRIMES for n in range(left, right + 1))
