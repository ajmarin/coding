class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        adj = defaultdict(list)
        for a, b in connections:
            adj[a].append((b, 1))
            adj[b].append((a, 0))

        def dfs(u, p):
            res = 0
            for v, flip in adj[u]:
                if v != p:
                    res += flip + dfs(v, u)
            return res

        return dfs(0, -1)
