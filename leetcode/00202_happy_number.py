class Solution:
    def squareSum(self, n: int) -> int:
        return 0 if n == 0 else self.squareSum(n // 10) + (n % 10) ** 2
    
    def isHappy(self, n: int, seen: set = None) -> bool:
        if seen is None:
            seen = set()
        if n in seen:
            return False
        seen.add(n)
        return n == 1 or self.isHappy(self.squareSum(n), seen)