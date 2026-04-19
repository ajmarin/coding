def rectangle_area(x1: int, y1: int, x2: int, y2: int) -> int:
    return (y2 - y1) * (x2 - x1)


class Solution:
    def computeArea(
        self,
        ax1: int,
        ay1: int,
        ax2: int,
        ay2: int,
        bx1: int,
        by1: int,
        bx2: int,
        by2: int,
    ) -> int:
        def get_overlap_area():
            xl, xr = max(ax1, bx1), min(ax2, bx2)
            if xl >= xr:
                return 0
            yb, yt = max(ay1, by1), min(ay2, by2)
            if yb >= yt:
                return 0
            return (xr - xl) * (yt - yb)

        area1 = rectangle_area(ax1, ay1, ax2, ay2)
        area2 = rectangle_area(bx1, by1, bx2, by2)
        return area1 + area2 - get_overlap_area()
