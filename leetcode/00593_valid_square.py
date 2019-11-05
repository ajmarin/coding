class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        xc = (p1[0] + p2[0] + p3[0] + p4[0]) / 4
        yc = (p1[1] + p2[1] + p3[1] + p4[1]) / 4
        def dist(a: List[int], b: List[int]) -> int:
            return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2
        d = dist(p1, (xc, yc))
        p1dists = []
        for p in (p2, p3, p4):
            if dist(p, (xc, yc)) != d:
                return False
            p1dists.append(dist(p1, p))
        p1dists.sort()
        return p1dists[0] > 0 and p1dists[0] == p1dists[1] and p1dists[0] + p1dists[1] == p1dists[2]