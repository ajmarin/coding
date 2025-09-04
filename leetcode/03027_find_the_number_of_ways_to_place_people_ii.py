class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda p: (p[0], -p[1]))
        yvals = [y for _, y in points]
        ans = 0
        for i, yi in enumerate(yvals):
            ymax = -inf
            for yj in yvals[i + 1:]:
                if yj > yi: continue
                if yj > ymax:
                    ans += 1
                    ymax = yj
        return ans
