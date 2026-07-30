class Solution:
    def largestInteger(self, n: int, s: int) -> int:
        if s > 9 * n:
            return -1
        res = 0
        for _ in range(n):
            d = min(s, 9)
            res = 10 * res + d
            s -= d
        return res
