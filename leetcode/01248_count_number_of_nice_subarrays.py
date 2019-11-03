class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        even_before = [0] * n
        even_after = [0] * n
        for i in range(1, n):
            even_before[i] = (not nums[i - 1] & 1) * (1 + even_before[i - 1])
        for i in range(n - 2, -1, -1):
            even_after[i] = (not nums[i + 1] & 1) * (1 + even_after[i + 1])
        if not any(x & 1 for x in nums):
            return 0
        left = next(i for i in range(n) if nums[i] & 1)
        right = left
        ans, odd_count = 0, 1
        while left < n:
            while right + 1 < n and odd_count < k:
                right += 1
                odd_count += nums[right] & 1
            if odd_count == k:
                ans += (even_before[left] + 1) * (even_after[right] + 1)
            left += 1
            odd_count -= 1
            while left < n and not nums[left] & 1:
                left += 1
        return ans