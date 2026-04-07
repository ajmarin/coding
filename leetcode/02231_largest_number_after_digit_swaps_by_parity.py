class Solution:
    def largestInteger(self, num: int) -> int:
        digits = []
        evens, odds = [], []
        while num:
            d = num % 10
            digits.append(d)
            (odds if d & 1 else evens).append(d)
            num //= 10
        evens.sort()
        odds.sort()
        ans = 0
        for d in digits[::-1]:
            ans = 10 * ans + (odds if d & 1 else evens).pop()
        return ans
