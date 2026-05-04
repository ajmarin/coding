class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        maxx = maxy = -1
        minx = miny = 1001
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val:
                    maxx = maxx if maxx > j else j
                    minx = minx if minx < j else j
                    maxy = maxy if maxy > i else i
                    miny = miny if miny < i else i
        return (maxx - minx + 1) * (maxy - miny + 1)
