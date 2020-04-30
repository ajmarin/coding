class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        def digits(n: int) -> int:
            return 1 + (n > 9) + (n > 99) + (n > 999) + (n > 9999) + (n > 99999)
        return len(list(filter(lambda n: not digits(n) & 1, nums)))