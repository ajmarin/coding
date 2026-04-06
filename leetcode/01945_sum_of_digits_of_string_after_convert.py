def digit_sum(n: int) -> int:
    res = 0
    while n:
        res += n % 10
        n //= 10
    return res


class Solution:
    def getLucky(self, s: str, k: int) -> int:
        total = sum(digit_sum(ord(c) - ord("a") + 1) for c in s)
        for _ in range(k - 1):
            total = digit_sum(total)
        return total
