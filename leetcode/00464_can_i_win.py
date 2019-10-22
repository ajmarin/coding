class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        memo = {}
        def solve(key: int, n: int, desiredTotal: int):
            top = n - 1
            while key & (1 << top):
                top -= 1
            if top + 1 >= desiredTotal:
                memo[key] = True
            if key in memo:
                return memo[key]
            ans = False
            for i in range(top):
                if key & (1 << i):
                    continue
                ans |= not solve(key | (1 << i), n, desiredTotal - i - 1)
                if ans:
                    break
            memo[key] = ans
            return ans
        z = maxChoosableInteger
        if z * (z + 1) < desiredTotal << 1:
            return False
        return solve(0, z, desiredTotal)