class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        ans = left = prev = 0
        dp = [0] * (1 + len(prizePositions))
        for right, num in enumerate(prizePositions, 1):
            while num - prizePositions[left] > k:
                left += 1
            curr = right - left
            prev = dp[right] = max(prev, curr)
            ans = ans if ans > curr + dp[left] else curr + dp[left]
        return ans
