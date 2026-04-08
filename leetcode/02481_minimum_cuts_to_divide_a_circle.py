class Solution:
    def numberOfCuts(self, n: int) -> int:
        if n == 1:
            return 0
        return n >> (n % 2 == 0)
