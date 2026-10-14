class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""
        nines, rem = sum // 9, sum % 9
        return "9" * nines + (str(rem) if rem else "") + "0" * (num - nines - (rem > 0))
