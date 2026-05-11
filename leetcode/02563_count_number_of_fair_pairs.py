class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        n = len(nums)
        left = right = n - 1
        ans = 0
        for i in range(n):
            upper_bound = upper - nums[i]
            while right and nums[right] > upper_bound:
                right -= 1
            if right <= i:
                break
            if nums[i] + nums[right] < lower:
                continue
            lower_bound = lower - nums[i]
            left = left if left <= right - 1 else right - 1
            while left > i and nums[left] >= lower_bound:
                left -= 1
            ans += right - left
            left += i == left
        return ans
