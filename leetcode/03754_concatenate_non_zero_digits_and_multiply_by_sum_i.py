class Solution:
    def sumAndMultiply(self, n: int) -> int:
        digits = deque([])
        while n:
            d = n % 10
            if d:
                digits.appendleft(d)
            n //= 10
        dsum = x = 0
        for d in digits:
            x = 10 * x + d
            dsum += d
        return dsum * x
