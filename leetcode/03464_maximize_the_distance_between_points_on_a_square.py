class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        n, perim = len(points), side << 2
        k -= 1
        p1d = []
        for x, y in points:
            if y == 0 or x == side:
                p1d.append(x + y)
            elif y == side:
                p1d.append(perim - x - y)
            else:
                p1d.append(perim - y)
        p1d.sort()

        def can_do(dist: int) -> bool:
            for at in p1d:
                limit_index = bisect_right(p1d, at + perim - dist)
                for _ in range(k):
                    if (i := bisect_left(p1d, at + dist)) >= limit_index:
                        break
                    at = p1d[i]
                else:
                    return True
            return False

        left, right = 1, side + 1
        while left < right:
            mid = (left + right) >> 1
            if can_do(mid):
                left = mid + 1
            else:
                right = mid
        return left - 1
