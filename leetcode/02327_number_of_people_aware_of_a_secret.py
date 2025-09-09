MOD = 10**9 + 7
class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1
        s = 0
        for day in range(delay + 1, forget):
            dp[day] = s = s + dp[day - delay]
        for day in range(forget, n + 1):
            dp[day] = s = (s + dp[day - delay] - dp[day - forget]) % MOD
        return (MOD + sum(dp[-forget:])) % MOD

