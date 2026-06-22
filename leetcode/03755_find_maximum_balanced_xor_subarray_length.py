class Solution:
    def maxBalancedSubarray(self, nums: List[int]) -> int:
        ans = bal = x = 0
        memo = {(0, 0): 0}
        for pos, n in enumerate(nums, 1):
            key = x, bal = x ^ n, bal + (1 if n & 1 else -1)
            if key in memo:
                ans = ans if ans >= pos - memo[key] else pos - memo[key]
            else:
                memo[key] = pos
        return ans
