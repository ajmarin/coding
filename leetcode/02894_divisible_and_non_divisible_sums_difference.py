class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        total = sum(range(n + 1))
        return total - 2 * sum(i for i in range(1, n + 1) if i % m == 0)
