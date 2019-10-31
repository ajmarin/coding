class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        # dp[i] = probability of having up to i
        # The game ended so dp[i] = 1.0 for i >= K
        # But we only want up to N, so dp[i] = 0 if i > N
        dp = [K <= i <= N for i in range(N + W + 1)]
        window_sum = min(N - K + 1, W)
        # working back to the start:
        for i in range(K - 1, -1, -1):
            dp[i] = window_sum / W
            window_sum += dp[i] - dp[i + W]
        return dp[0]