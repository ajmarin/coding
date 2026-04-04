class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n == 0:
            return 0
        nums = [0] * (n + 1)
        nums[1] = 1
        for i in range(2, len(nums)):
            halfi = i >> 1
            if i & 1:
                nums[i] = nums[halfi] + nums[halfi + 1]
            else:
                nums[i] = nums[halfi]
        return max(nums)
