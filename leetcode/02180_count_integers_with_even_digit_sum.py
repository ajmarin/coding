def digit_sum(num: int) -> int:
    res = 0
    while num:
        res += num % 10
        num //= 10
    return res


class Solution:
    def countEven(self, num: int) -> int:
        return sum(digit_sum(i) & 1 == 0 for i in range(1, num + 1))
