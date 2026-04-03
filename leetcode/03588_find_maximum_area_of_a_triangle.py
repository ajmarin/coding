class Solution:
    def maxArea(self, coords: List[List[int]]) -> int:
        min_x = min(p[0] for p in coords)
        max_x = max(p[0] for p in coords)
        min_y = min(p[1] for p in coords)
        max_y = max(p[1] for p in coords)

        by_x = {}
        by_y = {}

        max_area = 0

        for x, y in coords:
            if x not in by_x:
                by_x[x] = [y, y]
            else:
                limits = by_x[x]
                if y > limits[1]:
                    limits[1] = y
                    area = (y - limits[0]) * max(max_x - x, x - min_x)
                    max_area = area if area > max_area else max_area
                elif y < limits[0]:
                    limits[0] = y
                    area = (limits[1] - y) * max(max_x - x, x - min_x)
                    max_area = area if area > max_area else max_area
            if y not in by_y:
                by_y[y] = [x, x]
            else:
                limits = by_y[y]
                if x > limits[1]:
                    limits[1] = x
                    area = (x - limits[0]) * max(max_y - y, y - min_y)
                    max_area = area if area > max_area else max_area
                elif x < limits[0]:
                    limits[0] = x
                    area = (limits[1] - x) * max(max_y - y, y - min_y)
                    max_area = area if area > max_area else max_area

        return max_area - (max_area == 0)
