class Solution:
    def averageValue(self, nums: List[int]) -> int:
        valid = [n for n in nums if n % 6 == 0]
        return sum(valid) // len(valid) if valid else 0
