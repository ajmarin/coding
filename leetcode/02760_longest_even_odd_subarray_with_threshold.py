class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        n = len(nums)
        ans = left = right = 0
        while left < n:
            while left < n and (nums[left] > threshold or nums[left] & 1):
                left += 1
            if left == n:
                break
            parity = 1
            right = left + 1
            while right < n and nums[right] <= threshold:
                if nums[right] & 1 != parity:
                    break
                parity = 1 - parity
                right += 1
            if right - left > ans:
                ans = right - left
            left = right
        return ans
