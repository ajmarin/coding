class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums.sort(key=abs)
        left, right = 0, len(nums)
        ans = 0
        while left < right:
            ans += nums[right := right - 1] ** 2
            if left < right:
                ans -= nums[left] ** 2
                left += 1
        return ans
