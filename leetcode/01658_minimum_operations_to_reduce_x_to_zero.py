class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        n = len(nums)
        left, goal = -1, sum(nums) - x
        if goal == 0:
            return n
        if goal < 0:
            return -1

        curr, ans = 0, -1
        for right in range(n):
            curr += nums[right]
            while curr > goal:
                curr -= nums[left := left + 1]
            if curr == goal:
                ans = max(ans, right - left)

        return -(ans == -1) | n - ans
