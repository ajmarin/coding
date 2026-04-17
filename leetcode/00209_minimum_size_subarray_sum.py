class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans, left = 123456, -1
        running_sum = 0
        for i, n in enumerate(nums):
            running_sum += n
            while running_sum >= target:
                ans = ans if ans < i - left else i - left
                running_sum -= nums[left := left + 1]
        return ans if ans != 123456 else 0
