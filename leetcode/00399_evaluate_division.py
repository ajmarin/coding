class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        adj = defaultdict(list)

        for (a, b), val in zip(equations, values):
            adj[a].append((b, val))
            adj[b].append((a, 1 / val))

        def dfs(a, b, viz=None, result=1):
            if a not in adj or b not in adj:
                return -1
            if a == b:
                return result
            viz = viz or set()
            viz.add(a)
            for n, val in adj[a]:
                if n not in viz and (res := dfs(n, b, viz, result * val)) != -1:
                    return res
            return -1

        return [dfs(a, b) for a, b in queries]
