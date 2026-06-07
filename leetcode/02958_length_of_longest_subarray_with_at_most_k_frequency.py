class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        freq = {}
        ans = left = 0
        for right, n in enumerate(nums):
            freq[n] = freq.get(n, 0) + 1
            if freq[n] > k:
                ans = ans if ans >= right - left else right - left
                while freq[n] > k:
                    freq[nums[left]] -= 1
                    left += 1
        return max(ans, right - left + 1)
