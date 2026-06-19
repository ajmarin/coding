class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        ans, threshold = 0, -1
        for x in sorted(p[0] for p in points):
            if x > threshold:
                threshold = x + w
                ans += 1
        return ans
