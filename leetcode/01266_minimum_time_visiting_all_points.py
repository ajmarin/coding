class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        return sum(
            max(abs(p[0] - points[i][0]), abs(p[1] - points[i][1]))
            for i, p in enumerate(points[1:])
        )
