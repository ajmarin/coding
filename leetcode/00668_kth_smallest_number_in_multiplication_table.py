class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        class SmallerThan:
            def __getitem__(self, x):
                return sum(min(x // row, n) for row in range(1, m + 1))
        return bisect.bisect_left(SmallerThan(), k, 1, m * n)