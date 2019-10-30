class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total = sum(stones)
        half = total // 2
        dp = [0] * (half + 1)
        dp[0] = 1
        for s in stones:
            for i in range(half, s - 1, -1):
                dp[i] |= dp[i - s]
        return next(total - 2 * t for t in range(half, -1, -1) if dp[t])