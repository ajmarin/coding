class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(n < k for n in nums)
