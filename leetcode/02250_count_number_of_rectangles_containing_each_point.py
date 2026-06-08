class Solution:
    def countRectangles(
        self, rectangles: List[List[int]], points: List[List[int]]
    ) -> List[int]:
        by_y = [[] for _ in range(101)]
        for x, y in rectangles:
            by_y[y].append(x)
        for i in range(101):
            by_y[i].sort()
        ans = []
        for x, y in points:
            count = 0
            for y in range(y, 101):
                if not by_y[y]:
                    continue
                count += len(by_y[y]) - bisect_left(by_y[y], x)
            ans.append(count)
        return ans
