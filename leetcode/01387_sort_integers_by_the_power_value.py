@cache
def collatz(n: int) -> int:
    return 1 if n == 1 else 1 + collatz(3 * n + 1 if n & 1 else n >> 1)


class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        return sorted(range(lo, hi + 1), key=collatz)[k - 1]
