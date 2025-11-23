MAX_N = 10**6


def get_mins(seq):
    lowest, second = MAX_N, MAX_N
    for n in seq:
        if n < lowest:
            lowest, second = n, lowest
        elif n < second:
            second = n
    return lowest, second


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        total = sum(nums)
        remainder = total % 3
        if remainder == 0:
            return total

        mod1 = get_mins([n for n in nums if n % 3 == 1])
        mod2 = get_mins([n for n in nums if n % 3 == 2])

        remove = MAX_N
        if remainder == 1:
            remove = min(mod1[0], sum(mod2))
        else:
            remove = min(mod2[0], sum(mod1))
        return total - remove

