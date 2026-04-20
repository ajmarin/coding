class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [10**6] * (amount + 1)
        dp[0] = 0
        coins.sort()
        for i in range(1, amount + 1):
            min_amount = dp[i]
            for c in coins:
                if c > i:
                    break
                min_amount = min_amount if min_amount < dp[i - c] + 1 else dp[i - c] + 1
            dp[i] = min_amount
        return -(dp[amount] == 10**6) | dp[amount]
