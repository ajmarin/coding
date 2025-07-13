class Solution:
    def maxLen(self, n: int, edges: List[List[int]], label: str) -> int:
        adj = defaultdict(set)
        adj_label = defaultdict(lambda: defaultdict(set))
        def add_edge(u, v):
            adj[u].add(v)
            adj_label[u][label[v]].add(v)
        for u, v in edges: add_edge(u, v), add_edge(v, u)

        @cache
        def dfs(mask: int, left: int, right: int):
            if left > right: return dfs(mask, right, left)
            r = 0
            for u in adj[left]:
                if mask & (1 << u): continue
                for v in adj_label[right][label[u]]:
                    if mask & (1 << v): continue
                    rr = 3 if u == v else 2 + dfs(mask | (1 << u) | (1 << v), u, v)
                    r = rr if rr > r else r
            return r if r else (2 if left in adj[right] else -inf)

        ans = 1
        for u in range(n):
            for v in range(u + 1, n):
                if label[u] != label[v]: continue
                r = dfs((1 << u) | (1 << v), u, v)
                ans = r if r > ans else ans
        return ans

