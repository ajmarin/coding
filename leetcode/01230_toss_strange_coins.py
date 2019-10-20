class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        dp = [1] + [0] * target
        for p in prob:
            for h in range(target, -1, -1):
                dp[h] = (1 - p) * dp[h] + (p if h else 0) * dp[h - 1]
        return dp[target]