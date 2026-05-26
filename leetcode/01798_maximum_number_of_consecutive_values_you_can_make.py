class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        ans = 1
        coins.sort()
        for c in coins:
            if c > ans:
                break
            ans += c
        return ans
