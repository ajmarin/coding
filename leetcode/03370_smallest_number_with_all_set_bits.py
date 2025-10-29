class Solution:
    def smallestNumber(self, n: int) -> int:
        x = 1
        while x <= n:
            x <<= 1
        return x - 1
