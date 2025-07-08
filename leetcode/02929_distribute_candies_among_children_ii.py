class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        f = lambda n: (n + 2) * (n + 1) // 2 if n >= 0 else 0
        lp1 = limit + 1
        return f(n) - 3 * f(n - lp1) + 3 * f(n - 2 * lp1) - f(n - 3 * lp1)

