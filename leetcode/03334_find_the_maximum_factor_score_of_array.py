class Solution:
    def maxScore(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0] ** 2
        ans = reduce(gcd, nums, nums[0]) * reduce(lcm, nums, 1)
        for i in range(len(nums)):
            seq = nums[:i] + nums[i + 1 :]
            cand = reduce(gcd, seq, seq[0]) * reduce(lcm, seq, 1)
            ans = cand if cand > ans else ans
        return ans
