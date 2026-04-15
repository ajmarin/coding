class Solution:
    def evenNumberBitwiseORs(self, nums: List[int]) -> int:
        return reduce(lambda r, n: r | n if n % 2 == 0 else r, nums, 0)
