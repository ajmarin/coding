class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        n = len(nums)
        ans, mask = 0, 1
        for _ in range(32):
            ones = sum(1 for n in nums if n & mask)
            ans += ones * (n - ones)
            mask <<= 1
        return ans
