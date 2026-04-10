class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)
        return sum(
            all(a < b for a, b in pairwise(nums[:i] + nums[j:]))
            for i in range(n)
            for j in range(i + 1, n + 1)
        )
