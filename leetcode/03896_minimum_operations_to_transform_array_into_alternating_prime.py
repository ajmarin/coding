PRIMES = [2, 3]


def is_prime(n):
    for p in PRIMES:
        if p * p > n:
            return True
        if n % p == 0:
            return False
    return True


for i in range(5, 100_009, 2):
    if is_prime(i):
        PRIMES.append(i)


PRIME_SET = set(PRIMES)


class Solution:
    def minOperations(self, nums: list[int]) -> int:
        ans = 0
        for n in nums[::2]:
            if n not in PRIME_SET:
                ans += PRIMES[bisect_right(PRIMES, n)] - n
        for n in nums[1::2]:
            if n in PRIME_SET:
                ans += 1 + (n == 2)
        return ans
