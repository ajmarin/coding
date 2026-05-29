N = 500_001
is_prime = [True] * N
for i in range(4, N, 2):
    is_prime[i] = False

prime_prefix = [2]
s = 2
for i in range(3, N, 2):
    if is_prime[i]:
        for j in range(i * i, N, i << 1):
            is_prime[j] = False
        s += i
        if s < N and is_prime[s]:
            prime_prefix.append(s)


class Solution:
    def largestPrime(self, n: int) -> int:
        return 0 if n < 2 else prime_prefix[bisect_right(prime_prefix, n) - 1]
