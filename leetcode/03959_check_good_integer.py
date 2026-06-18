ADD = [d * (d - 1) for d in range(10)]


class Solution:
    def checkGoodInteger(self, n: int) -> bool:
        diff = 0
        while n and diff < 50:
            diff += ADD[n % 10]
            n //= 10
        return diff >= 50
