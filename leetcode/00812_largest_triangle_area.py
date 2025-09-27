class Point:
    def __init__(self, x: int, y: int):
        self.x, self.y = x, y

    def __sub__(self, o: "Point"):
        return Point(self.x - o.x, self.y - o.y)

    def __mul__(self, o: "Point"):
        return self.x * o.y - self.y * o.x


class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return (
            max(
                abs((b - a) * (c - a))
                for a, b, c in combinations(
                    map(lambda coords: Point(*coords), points), 3
                )
            )
            / 2
        )
