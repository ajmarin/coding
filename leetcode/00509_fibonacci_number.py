f = [0, 1]
for i in range(2, 31):
    f.append(f[-1] + f[-2])


class Solution:
    def fib(self, n: int) -> int:
        return f[n]
