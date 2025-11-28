class Solution:
    def maxKDivisibleComponents(
        self, n: int, edges: List[List[int]], values: List[int], k: int
    ) -> int:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        ans = [0]
        visited = [False] * n

        def dfs(at):
            visited[at] = True
            total = values[at]
            for u in adj[at]:
                if visited[u]:
                    continue
                total += dfs(u)

            if total % k == 0:
                ans[0] += 1
                return 0
            return total

        dfs(0)
        return ans[0]
