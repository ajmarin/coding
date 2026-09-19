def interval_dist(x: int, a: int, b: int) -> int:
    if x < a:
        return a - x
    if x > b:
        return x - b
    return 0


class Solution:
    def checkOverlap(
        self,
        radius: int,
        xCenter: int,
        yCenter: int,
        x1: int,
        y1: int,
        x2: int,
        y2: int,
    ) -> bool:
        return (x1 <= xCenter <= x2 and y1 <= yCenter <= y2) or interval_dist(
            xCenter, x1, x2
        ) ** 2 + interval_dist(yCenter, y1, y2) ** 2 <= radius**2
