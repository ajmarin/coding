class Solution:
    def maximumSwap(self, num: int) -> int:
        d = []
        while num:
            d = [num % 10] + d
            num //= 10
        lend = len(d)
        answer = d.copy()
        for i in range(lend):
            for j in range(i + 1, lend):
                d[i], d[j] = d[j], d[i]
                if d > answer:
                    answer = d.copy()
                d[i], d[j] = d[j], d[i]
        return ''.join(map(str,answer))