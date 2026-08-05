class Solution:
    def maxPairStrength(self, nums: list[int]) -> int:
        return max(a * b // gcd(a, b) ** 2 for a, b in combinations(nums, 2))
