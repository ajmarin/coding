class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        previous = "@"
        ans = highest = 0
        for c, t in zip(colors, neededTime):
            if c != previous:
                highest = t
            elif t > highest:
                ans += highest
                highest = t
            else:
                ans += t
            previous = c
        return ans
