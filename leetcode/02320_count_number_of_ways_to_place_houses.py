MOD = 10**9 + 7

class Solution:
    def countHousePlacements(self, n: int) -> int:
        prev, curr = 1, 2
        for i in range(1, n):
            prev, curr = curr, (prev + curr) % MOD
        return curr * curr % MOD

