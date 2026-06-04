def get_waviness(n: int) -> int:
    waviness = 0
    d = []
    while n:
        d.append(n % 10)
        n //= 10
    for i in range(1, len(d) - 1):
        waviness += (d[i - 1] < d[i] > d[i + 1]) or (d[i - 1] > d[i] < d[i + 1])
    return waviness


class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        return sum(map(get_waviness, range(num1, num2 + 1)))
