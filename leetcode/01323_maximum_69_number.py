class Solution:
    def maximum69Number(self, num: int) -> int:
        digits = []
        index = -1
        while num:
            n = num % 10
            if n == 6:
                index = len(digits)
            digits.append(n)
            num //= 10
        digits[index] = 9
        ans = 0
        for d in reversed(digits):
            ans = ans * 10 + d
        return ans
