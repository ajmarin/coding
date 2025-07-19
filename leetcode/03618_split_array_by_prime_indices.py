primes = deque([2, 3, 5, 7])

for n in range(11, 100001, 2):
    is_prime = True
    for p in primes:
        if p * p > n: break
        if not (is_prime := is_prime and n % p != 0): break
    if is_prime: primes.append(n)

primes = set(primes)

class Solution:
    def splitArray(self, nums: List[int]) -> int:
        total = sum(nums)
        prime_sum = sum(n for i, n in enumerate(nums) if i in primes)
        return abs(total - 2 * prime_sum)

