class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        adj = [[] for _ in range(n)]
        low_cost = [[10**9] * (k + 1) for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))

        goal, heap = n - 1, [(0, 0, 1)]
        while heap:
            cost, u, repeated = heappop(heap)
            if u == goal:
                return cost
            for v, w in adj[u]:
                rep = 1 if labels[v] != labels[u] else repeated + 1
                if rep > k or low_cost[v][rep] <= cost + w:
                    continue
                low_cost[v][rep] = cost + w
                heappush(heap, (cost + w, v, rep))

        return -1
