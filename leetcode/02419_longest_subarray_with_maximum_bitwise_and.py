class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        x = max(nums)
        ans = cnt = 0
        for n in nums:
            if n != x: cnt = 0
            else:
                cnt += 1
                ans = cnt if cnt > ans else ans
        return ans

