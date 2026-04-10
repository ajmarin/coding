class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        n = len(nums)
        return sum(
            nums[i] + nums[j] < target for i in range(n) for j in range(i + 1, n)
        )
