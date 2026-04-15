class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        return gcd(n**2, n**2 + n)
