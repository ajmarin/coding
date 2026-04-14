class Solution:
    def maxProduct(self, n: int) -> int:
        digits = []
        while n:
            digits.append(n % 10)
            n //= 10
        digits.sort()
        return digits[-1] * digits[-2]
