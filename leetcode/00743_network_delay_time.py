class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = defaultdict(list)
        for u, v, w in times:
            adj[u].append((v, w))

        q = [(0, k)]
        cost = {k: 0}
        while q:
            t, u = heappop(q)
            if t > cost[u]:
                continue
            for v, w in adj[u]:
                if v not in cost:
                    cost[v] = t + w
                    heappush(q, (t + w, v))
                elif t + w < cost[v]:
                    heappush(q, (t + w, v))
                    cost[v] = t + w
        return max(cost.values()) if len(cost) == n else -1
