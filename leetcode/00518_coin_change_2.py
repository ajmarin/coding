class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        amount += 1
        dp = [0] * amount
        dp[0] = 1
        for c in coins:
            for i in range(c, amount):
                dp[i] += dp[i - c]
        return dp[-1]