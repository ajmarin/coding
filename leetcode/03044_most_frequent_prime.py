DIRS = ((-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0))
PRIMES = [2, 3]


def is_prime(n):
    for p in PRIMES:
        if p * p > n:
            break
        if n % p == 0:
            return False
    return True


for n in range(5, 1_000_000, 2):
    if is_prime(n):
        PRIMES.append(n)


class Solution:
    def mostFrequentPrime(self, mat: List[List[int]]) -> int:
        cnt = Counter()
        rows, cols = len(mat), len(mat[0])
        for r in range(rows):
            for c in range(cols):
                for dr, dc in DIRS:
                    nr, nc, num = r, c, 0
                    while 0 <= nr < rows and 0 <= nc < cols:
                        num = 10 * num + mat[nr][nc]
                        if num > 10 and is_prime(num):
                            cnt[num] += 1
                        nr += dr
                        nc += dc
        return max(cnt.keys(), key=lambda n: (cnt[n], n), default=-1)
