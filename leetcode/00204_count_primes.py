class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        prime = [True] * n
        for i in range(4, n, 2):
            prime[i] = False
        count = 1
        for i in range(3, n, 2):
            if not prime[i]:
                continue
            count += 1
            j = i * i
            while j < n:
                prime[j] = False
                j += i
        return count