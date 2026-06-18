class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans
