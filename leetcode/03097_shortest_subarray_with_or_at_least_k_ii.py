class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if not k or max(nums) >= k:
            return 1
        ans = 10**9
        for right, num in enumerate(nums):
            for left in range(right - 1, -1, -1):
                if nums[left] | num == nums[left]:
                    break
                nums[left] |= num
                if nums[left] >= k:
                    ans = ans if ans < right - left else right - left
        return -(ans == 10**9) | (ans + 1)
