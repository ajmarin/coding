class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        total = sum(nums)
        ans = left = 0
        for n in nums[:-1]:
            left += n << 1
            ans += abs(total - left) % 2 == 0
        return ans
