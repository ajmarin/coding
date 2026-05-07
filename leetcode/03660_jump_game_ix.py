class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        high = -1
        ans = nums[:]
        for i, n in enumerate(nums):
            if n < high:
                ans[i] = high
            else:
                high = n
        left = len(nums) - 1
        for i in range(len(nums) - 1, 0, -1):
            left -= left == i
            while left >= 0 and ans[left] > nums[i]:
                ans[left] = ans[i]
                left -= 1
            if left == -1:
                break
        return ans
