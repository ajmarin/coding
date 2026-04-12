class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False] * n

        def dfs(u):
            visited[u] = True
            for v, connected in enumerate(isConnected[u]):
                if connected and not visited[v]:
                    dfs(v)

        ans = 0
        for u in range(n):
            if not visited[u]:
                ans += 1
                dfs(u)
        return ans
