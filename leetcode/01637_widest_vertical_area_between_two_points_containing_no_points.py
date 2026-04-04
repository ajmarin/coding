class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        x = sorted(set(p[0] for p in points))
        return max((n - x[i] for i, n in enumerate(x[1:])), default=0)
