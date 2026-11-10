class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        n += 1
        dp = [0] + [*costs]
        dp[1] += 1 + dp[0]
        if n < 3:
            return dp[-1]
        dp[2] += min(dp[0] + 4, dp[1] + 1)
        p3, p2, p1 = dp[:3]
        for i in range(3, n):
            dp[i] += min(p1 + 1, p2 + 4, p3 + 9)
            p1, p2, p3 = dp[i], p1, p2

        return p1
