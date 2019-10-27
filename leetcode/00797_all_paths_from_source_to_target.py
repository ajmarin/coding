class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        N = len(graph)
        ans = [collections.deque() for _ in range(N)]
        visited = [False] * N
        def dfs(n: int):
            if visited[n]:
                return ans[n]
            if n == N - 1:
                ans[n].append([n])
                return ans[n]
            for c in graph[n]:
                ans[n].extend([n] + path for path in dfs(c))
                visited[c] = True
            return ans[n]
        return dfs(0)