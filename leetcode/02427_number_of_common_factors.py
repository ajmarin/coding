class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        ans = 0
        for i in range(1, max(a, b) + 1):
            ans += a % i == b % i == 0
        return ans
