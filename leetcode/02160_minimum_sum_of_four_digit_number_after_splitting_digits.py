class Solution:
    def minimumSum(self, num: int) -> int:
        d = []
        while num:
            d.append(num % 10)
            num //= 10
        d.sort()
        return 10 * (d[0] + d[1]) + d[2] + d[3]
