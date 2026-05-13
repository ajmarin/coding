class Solution:
    def maxSubarrays(self, nums: List[int]) -> int:
        ans, curr = 0, -1
        for n in nums:
            curr &= n
            if not curr:
                ans += 1
                curr = -1
        return max(ans, 1)
