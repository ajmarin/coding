PRIMES = [2, 3]
PRIMES_SET = set(PRIMES)


def is_prime(n: int) -> bool:
    return n > 1 and (n in PRIMES_SET or all(n % p != 0 for p in PRIMES))


for n in range(5, 2000, 2):
    if all(n % p != 0 for p in PRIMES):
        PRIMES.append(n)
        PRIMES_SET.add(n)


class Solution:
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        ans = 0
        for i in range(len(nums)):
            a, b = nums[i][i], nums[i][~i]
            if is_prime(a):
                ans = max(ans, a)
            if is_prime(b):
                ans = max(ans, b)
        return ans
