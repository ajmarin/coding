def get_digit_range(x: int):
    low = high = x % 10
    x //= 10
    while x:
        d = x % 10
        x //= 10
        if d < low:
            low = d
        elif d > high:
            high = d
    return high - low


class Solution:
    def maxDigitRange(self, nums: list[int]) -> int:
        digit_range, total = -1, 0
        for n in nums:
            rng = get_digit_range(n)
            if rng > digit_range:
                digit_range = rng
                total = 0
            if rng == digit_range:
                total += n
        return total
