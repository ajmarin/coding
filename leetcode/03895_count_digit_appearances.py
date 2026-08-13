class Solution:
    def countDigitOccurrences(self, nums: list[int], digit: int) -> int:
        d = str(digit)
        return sum(str(n).count(d) for n in nums)
