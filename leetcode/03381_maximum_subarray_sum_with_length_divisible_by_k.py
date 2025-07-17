class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums) + 1
        acc = [0, *accumulate(nums)]
        dp = [-inf] * n
        ans = -inf
        for i, psum in enumerate(acc[k:]):
            prev = dp[i]
            prev = prev if prev > 0 else 0
            cand = psum - acc[i] + prev
            dp[i + k] = cand
            ans = cand if cand > ans else ans
        return ans

