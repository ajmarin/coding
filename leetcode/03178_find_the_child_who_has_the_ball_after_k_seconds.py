class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        k %= 2 * (n - 1)
        return k if k <= n - 1 else 2 * (n - 1) - k
