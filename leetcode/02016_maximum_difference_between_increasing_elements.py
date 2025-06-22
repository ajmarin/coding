class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans = -1
        low = nums[0]
        for n in nums[1:]:
            if n > low:
                ans = max(ans, n - low)
            else:
                low = n
        return ans

