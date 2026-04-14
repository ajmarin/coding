def digit_sum(n: int) -> int:
    res = 0
    while n:
        res += n % 10
        n //= 10
    return res


class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        return next((i for i, n in enumerate(nums) if digit_sum(n) == i), -1)
