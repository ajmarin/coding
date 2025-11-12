class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if 1 in nums:
            return n - nums.count(1)
        low = n + 1
        for start in range(n):
            g = nums[start]
            for end in range(start + 1, start + low if start + low < n else n):
                g = gcd(g, nums[end])
                if g == 1:
                    low = end + 1 - start
                    break
        return low + n - 2 if low <= n else -1
