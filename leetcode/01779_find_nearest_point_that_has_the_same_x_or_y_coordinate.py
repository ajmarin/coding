class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        ans, dist = -1, inf
        for i, p in enumerate(points):
            if p[0] == x or p[1] == y:
                d = abs(p[0] - x) + abs(p[1] - y)
                if d < dist:
                    ans = i
                    dist = d
        return ans
