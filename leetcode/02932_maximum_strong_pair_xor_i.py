class Solution:
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        return max(a ^ b for a, b in product(nums, nums) if abs(a - b) <= min(a, b))
