class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        ans = prev = 0
        for i, n in enumerate(values):
            ans = ans if ans > prev + n - i else prev + n - i
            prev = prev if prev > n + i else n + i
        return ans
