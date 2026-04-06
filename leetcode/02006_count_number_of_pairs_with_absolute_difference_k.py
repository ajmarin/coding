class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        n = len(nums)
        return sum(
            abs(nums[j] - nums[i]) == k for i in range(n) for j in range(i + 1, n)
        )
