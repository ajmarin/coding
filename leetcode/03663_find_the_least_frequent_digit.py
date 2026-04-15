class Solution:
    def getLeastFrequentDigit(self, n: int) -> int:
        f = [0] * 10
        while n:
            f[n % 10] += 1
            n //= 10

        ans, low = 0, 15
        for i, cnt in enumerate(f):
            if 0 < cnt < low:
                low = cnt
                ans = i
        return ans
