def digit_sum(n: int) -> int:
    res = 0
    while n:
        res += n % 10
        n //= 10
    return res


class Solution:
    def minElement(self, nums: List[int]) -> int:
        return min(digit_sum(n) for n in nums)
