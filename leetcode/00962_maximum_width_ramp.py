class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack = [0]
        for i in range(1, len(nums)):
            if nums[i] < nums[stack[-1]]:
                stack.append(i)

        ans = 0
        for i in range(len(nums) - 1, -1, -1):
            while stack and nums[i] >= nums[stack[-1]]:
                ans = max(ans, i - stack.pop())
            if not stack:
                break
        return ans
