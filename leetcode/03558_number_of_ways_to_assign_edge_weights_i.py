class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(len(edges) + 2)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(u: int, p: int) -> int:
            max_depth = -1
            for v in adj[u]:
                if v == p:
                    continue
                depth = dfs(v, u)
                max_depth = depth if depth > max_depth else max_depth
            return max_depth + 1

        return pow(2, dfs(1, -1) - 1, 10**9 + 7)
