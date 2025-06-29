MOD = 10**9 + 7

class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans, left, right = 0, 0, len(nums) - 1
        while left <= right:
            total = nums[left] + nums[right]
            if total > target:
                right -= 1
                continue
            ans = (ans + pow(2, right - left, MOD)) % MOD
            left += 1
        return ans

