class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        biggest = max(nums)
        return (2 * biggest + k - 1) * k // 2
