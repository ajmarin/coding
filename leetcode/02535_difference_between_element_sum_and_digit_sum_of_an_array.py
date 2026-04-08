def digit_sum(num: int) -> int:
    res = 0
    while num:
        res += num % 10
        num //= 10
    return res


class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        return sum(nums) - sum(digit_sum(n) for n in nums)
