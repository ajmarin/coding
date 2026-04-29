class Solution:
    def centeredSubarrays(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for left in range(n):
            seen, total = set(), 0
            for right in range(left, n):
                seen.add(nums[right])
                total += nums[right]
                ans += total in seen
        return ans
