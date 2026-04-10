def get_largest_digit(n: int) -> int:
    digit = n % 10
    while n:
        curr = n % 10
        digit = curr if curr > digit else digit
        n //= 10
    return digit


class Solution:
    def maxSum(self, nums: List[int]) -> int:
        max_by_largest_digit = {}
        ans = -1
        for n in nums:
            digit = get_largest_digit(n)
            if digit in max_by_largest_digit:
                val = max_by_largest_digit[digit]
                max_by_largest_digit[digit] = n if n > val else val
                ans = n + val if n + val > ans else ans
            else:
                max_by_largest_digit[digit] = n
        return ans
