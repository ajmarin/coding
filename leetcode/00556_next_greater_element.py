class Solution:
    def nextGreaterElement(self, n: int) -> int:
        d = []
        while n:
            d.append(n % 10)
            n //= 10
        n = len(d)
        d[:] = d[::-1]

        pivot = -1
        for i in range(n - 2, -1, -1):
            if d[i] < d[i + 1]:
                pivot = i
                break
        if pivot == -1:
            return -1

        for i in range(n - 1, pivot, -1):
            if d[i] > d[pivot]:
                d[pivot], d[i] = d[i], d[pivot]
                break
        d[pivot + 1 :] = d[:pivot:-1]
        res = 0
        for n in d:
            res = res * 10 + n
        return res if res < 1 << 31 else -1
