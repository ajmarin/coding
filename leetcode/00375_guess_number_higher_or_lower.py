class Solution:
    def getMoneyAmount(self, n: int) -> int:
        @cache
        def dp(start, end):
            if start >= end:
                return 0
            return min(
                mid + max(dp(start, mid - 1), dp(mid + 1, end))
                for mid in range(start, end + 1)
            )

        return dp(1, n)
