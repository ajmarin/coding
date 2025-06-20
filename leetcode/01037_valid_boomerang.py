class Solution:
    def sub(self, a: List[int], b: List[int]) -> (int, int):
        return b[0] - a[0], b[1] - a[1]

    def isBoomerang(self, points: List[List[int]]) -> bool:
        points.sort()
        dx1, dy1 = self.sub(points[0], points[1])
        dx2, dy2 = self.sub(points[1], points[2])
        return dx1 * dy2 - dx2 * dy1 != 0

