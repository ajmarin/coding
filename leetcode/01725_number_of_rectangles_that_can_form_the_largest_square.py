class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        sides = [min(l, w) for l, w in rectangles]
        max_len = max(sides)
        return sum(s == max_len for s in sides)
