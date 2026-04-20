class Solution:
    def integerBreak(self, n: int) -> int:
        ans = 1
        for i in range(2, n):
            div = n // i
            rem = n % i
            cand = i**div
            if rem == 1 and div > 1:
                cand = cand // i * (i + 1)
            elif rem:
                cand *= rem
            ans = ans if ans > cand else cand
        return ans
