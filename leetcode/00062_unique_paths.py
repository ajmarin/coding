class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m <= 0 or n <= 0:
            return 0
        ways = 1
        moves = m + n - 2
        stop = min(m, n) - 1
        for i in range(stop):
            ways *= moves - i
            ways //= i + 1
        return ways