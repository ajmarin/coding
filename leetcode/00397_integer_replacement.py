class Solution:
    def integerReplacement(self, n: int, count=0) -> int:
        if n == 1:
            return count
        if not n & 1:
            return self.integerReplacement(n >> 1, count + 1)
        if n == 3 or not n & 2:
            return self.integerReplacement((n - 1) >> 1, count + 2)
        return self.integerReplacement((n + 1) >> 1, count + 2)
