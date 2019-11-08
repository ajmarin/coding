class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        target += 1
        dp = [0] * (target)
        dp[target - 1] = 1
        for i in range(target - 1, -1, -1):
            for n in nums:
                if n <= i:
                    dp[i - n] += dp[i]
        return dp[0]