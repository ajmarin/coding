class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        bottom, top = inf, -inf
        total_area = 0
        areas = []
        tops = []
        for _, y, side in squares:
            my_top = y + side
            tops.append(my_top)
            area = side * side
            total_area += area
            areas.append(side * side)
            bottom = y if y < bottom else bottom
            top = my_top if my_top > top else top

        def getAreaBelow(index: int, cut_y: float) -> float:
            _, y, side = squares[index]
            if cut_y >= tops[index]: return areas[index]
            if cut_y < y: return 0
            return side * (cut_y - y)


        n = len(squares)
        target = total_area / 2
        EPS = 5e-6
        while abs(top - bottom) > EPS:
            cut = (bottom + top) / 2
            area = sum(getAreaBelow(i, cut) for i in range(n))
            if area < target: bottom = cut + EPS
            else: top = cut - EPS
        return bottom

