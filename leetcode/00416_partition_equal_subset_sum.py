class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        N = len(nums)
        nums.sort()
        total = sum(nums)
        if total & 1:
            return False
        total >>= 1
        dp = [False] * (total + 1)
        dp[0] = True
        rsum = 0
        for n in nums:
            rsum += n
            for i in range(min(rsum, total), n - 1, -1):
                dp[i] |= dp[i - n]
            if dp[total]:
                return True
        return False