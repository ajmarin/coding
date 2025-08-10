def count(x):
    res = 0
    while x:
        res += 10 ** (x % 10)
        x //= 10
    return res

POW2_COUNTS = [count(1 << i) for i in range(32)]

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        count_n = count(n)
        return any(count_n == pow2_count for pow2_count in POW2_COUNTS)

