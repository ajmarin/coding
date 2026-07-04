class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = [[] for _ in range(n + 1)]
        viz = [False] * (n + 1)

        for u, v, cost in roads:
            adj[u].append((v, cost))
            adj[v].append((u, cost))

        def dfs(u: int) -> int:
            low = 10_000
            viz[u] = True
            for v, cost in adj[u]:
                if not viz[v]:
                    cand = dfs(v)
                    cost = cost if cost <= cand else cand
                low = low if low <= cost else cost
            return low

        return dfs(1)
