class Solution:
    def maxLength(self, nums: List[int]) -> int:
        ans, left, prod = 2, -1, 1
        for right, n in enumerate(nums):
            while prod * n != lcm(prod, n):
                prod //= nums[left := left + 1]
            prod *= n
            ans = right - left if right - left > ans else ans
        return ans
