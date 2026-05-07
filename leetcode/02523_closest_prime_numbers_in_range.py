PRIMES = [2, 3]


def is_prime(n: int) -> bool:
    for j in PRIMES:
        if n % j == 0:
            return False
        if j * j > n:
            return True
    return True


for i in range(5, 1_000_000, 2):
    if is_prime(i):
        PRIMES.append(i)


class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        ans = [-1, -1]
        min_diff = 10**7
        index = bisect_left(PRIMES, left)
        if index >= len(PRIMES):
            return ans
        prev = PRIMES[index]
        for i in range(index + 1, len(PRIMES)):
            if PRIMES[i] > right:
                break
            p = PRIMES[i]
            if p - prev < min_diff:
                min_diff = p - prev
                ans = [prev, p]
            prev = p
        return ans
