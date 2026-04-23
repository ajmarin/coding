class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        n = len(points)
        dist = lambda p1, p2: (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
        ans = 0
        for i, p1 in enumerate(points):
            by_dist = defaultdict(list)
            for j, p2 in enumerate(points):
                by_dist[dist(p1, p2)].append(j)
            for l in by_dist.values():
                if (count := len(l)) > 1:
                    ans += count * (count - 1)
        return ans
