class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n = len(nums)
        while n > 1:
            for i in range(n // 2):
                fn = max if i & 1 else min
                nums[i] = fn(nums[2 * i], nums[2 * i + 1])
            n >>= 1
        return nums[0]
