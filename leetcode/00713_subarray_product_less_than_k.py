class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0

        ans = left = 0
        prod = 1
        for right, num in enumerate(nums, start=1):
            prod *= num
            while prod >= k:
                prod //= nums[left]
                left += 1
            ans += right - left
        return ans
