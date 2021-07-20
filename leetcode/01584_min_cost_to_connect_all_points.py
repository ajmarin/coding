class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # Union Find
        parent = list(range(len(points)))
        def find(u):
            while parent[u] != u:
                u, parent[u] = parent[u], parent[parent[u]]
            return u
        def union(u, v):
            u = find(u)
            v = find(v)
            if u == v:
                return False
            parent[v] = u
            return True
        # Manhattan distance
        dist = lambda p1, p2: abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
        # Connect
        cost = 0
        connected = 1
        edges = []
        for a, p1 in enumerate(points):
            for b in range(a + 1, len(points)):
                edges.append((dist(p1, points[b]), a, b))
        for edge in sorted(edges):
            weight, a, b = edge
            if union(a, b):
                connected += 1
                cost += weight
                if connected == len(points):
                    break
        return cost
