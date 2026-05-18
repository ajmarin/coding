class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        k += 1

        @cache
        def dp(dice: int, total: int) -> int:
            if dice == 0:
                return total == target
            if total > target:
                return 0
            dice -= 1
            return sum(dp(dice, total + x) for x in range(1, k)) % (10**9 + 7)

        return dp(n, 0)
