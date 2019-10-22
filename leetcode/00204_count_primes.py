class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        prime = [True] * n
        prime[0] = 0
        prime[1] = 0
        for i in range(2, n):
            if not prime[i]:
                continue
            if i * i > n:
                break
            for j in range(i * i, n, i):
                prime[j] = False
        return sum(prime)