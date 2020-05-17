import cmath

class Solution:
    def findBest(self, i: int, r: float, n: int) -> int:
        angles = []
        p = self.p
        diam = 2 * r
        for j in range(n):
            if i != j and self.d[i][j] <= diam:
                b = math.acos(self.d[i][j] / float(diam))
                a = cmath.phase(p[j] - p[i])
                angles.append((a - b, -1))
                angles.append((a + b, 1))
        angles.sort()
        count = res = 1
        for _, sub in angles:
            count -= sub
            res = max(res, count)
        return res
                
    def numPoints(self, points: List[List[int]], r: int) -> int:
        n = len(points)
        self.p = list(map(lambda p: complex(*p), points))
        self.d = d = [[None] * n for _ in range(n)]
        for i in range(n):
            for j in range(i + 1, n):
                d[i][j] = d[j][i] = abs(self.p[i] - self.p[j])
        ans = 1
        for i in range(n):
            ans = max(ans, self.findBest(i, float(r), n))
        return ans