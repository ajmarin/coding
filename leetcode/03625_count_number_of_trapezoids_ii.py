class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        slopes = Counter()
        lines = Counter()
        midpoints = Counter()
        midlines = Counter()

        for i, (x1, y1) in enumerate(points):
            for x2, y2 in points[i + 1:]:
                dx, dy = x2 - x1, y2 - y1
                g = gcd(dx, dy)
                dx, dy = dx // g, dy // g
                if dx < 0 or (dx == 0 and dy < 0):
                    dx, dy = -dx, -dy
                line = dx * y1 - dy * x1

                slopes[dx, dy] += 1
                lines[dx, dy, line] += 1
                mx, my = x1 + x2, y1 + y2
                midpoints[mx, my] += 1
                midlines[mx, my, dx, dy, line] += 1

        c = lambda l: sum(comb(x, 2) for x in l.values())
        return c(slopes) - c(lines) - (c(midpoints) - c(midlines))

