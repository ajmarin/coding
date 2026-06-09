class Solution:
    def maxWeight(self, n: int, edges: List[List[int]], k: int, t: int) -> int:
        adj = defaultdict(list)
        for u, v, w in edges:
            adj[u].append((v, w))

        ans = -1
        q = deque([])
        viz = set()
        weights = [[set() for _ in range(k + 1)] for _ in range(n)]
        for start in range(n):
            q.append((start, 0))
            viz.add((start, 0))
            weights[start][0].add(0)

        while q:
            u, d = q.popleft()
            weightsud = weights[u][d]
            if d == k:
                if weightsud:
                    ans = max(ans, max(weightsud))
                continue
            d += 1
            for v, cost in adj[u]:
                if (v, d) not in viz:
                    q.append((v, d))
                    viz.add((v, d))
                weightsvd = weights[v][d]
                cap = t - cost
                for w in weightsud:
                    if w < cap:
                        weightsvd.add(w + cost)
        return ans
