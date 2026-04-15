class Solution:
    def removeZeros(self, n: int) -> int:
        digits = []
        while n:
            d = n % 10
            if d:
                digits.append(d)
            n //= 10
        ans = 0
        for d in reversed(digits):
            ans = 10 * ans + d
        return ans
