class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        pp, p = nums[:2]
        ans = count = 2
        for n in nums[2:]:
            if n == p + pp:
                count += 1
                ans = count if count > ans else ans
            else:
                count = 2
            pp, p = p, n
        return ans
