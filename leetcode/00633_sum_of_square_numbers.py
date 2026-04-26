PRIMES = [2, 3]


for i in range(5, 65537, 2):
    if all(i % p != 0 for p in PRIMES):
        PRIMES.append(i)


class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        count = 0
        for p in PRIMES:
            if p * p > c:
                break
            if c % p:
                continue
            count = 1
            c //= p
            while c % p == 0:
                c //= p
                count += 1
            if p & 3 == 3 and count & 1:
                return False
        return c & 3 != 3
