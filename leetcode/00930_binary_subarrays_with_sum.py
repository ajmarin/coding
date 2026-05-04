class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n = len(nums)
        ones = [-1] + [i for i in range(n) if nums[i]] + [n]
        if goal == 0:
            return sum((b - a) * (b - a - 1) for a, b in pairwise(ones)) >> 1
        ans, left = 0, 1
        for right in range(goal, len(ones) - 1):
            zeroes_before = ones[left] - ones[left - 1]
            zeroes_after = ones[right + 1] - ones[right]
            left += 1
            ans += zeroes_before * zeroes_after
        return ans
