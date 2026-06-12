MOD, N = 10**9 + 7, 100_002
f = [0] * N
f[1] = 1
for i in range(2, N):
    f[i] = 2 * f[i - 1] % MOD


class Solution:
    def preprocess(self, edges: List[List[int]]):
        n = len(edges) + 2
        self.adj = [[] for _ in range(n)]
        self.depth = [0] * n
        self.enter = [-1] * n
        self.height = ceil(log2(n))
        self.leave = [-1] * n
        self.up = [[0] * (self.height + 1) for _ in range(n)]
        self.t = 0

        for u, v in edges:
            self.adj[u].append(v)
            self.adj[v].append(u)
        self.dfs(1, 1)

    def dfs(self, u: int, p: int):
        self.t += 1
        self.enter[u] = self.t
        self.depth[u] = self.depth[p] + 1
        upu = self.up[u]
        upu[0] = p
        for i in range(1, self.height + 1):
            upu[i] = self.up[upu[i - 1]][i - 1]

        for v in self.adj[u]:
            if v != p:
                self.dfs(v, u)

        self.t += 1
        self.leave[u] = self.t

    def is_ancestor(self, u: int, v: int) -> bool:
        return self.enter[u] <= self.enter[v] and self.leave[v] <= self.leave[u]

    def lca(self, u: int, v: int) -> int:
        if self.is_ancestor(u, v):
            return u
        if self.is_ancestor(v, u):
            return v
        for i in range(self.height, -1, -1):
            if not self.is_ancestor(self.up[u][i], v):
                u = self.up[u][i]
        return self.up[u][0]

    def assignEdgeWeights(
        self, edges: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        self.preprocess(edges)
        d = self.depth
        return [f[d[u] + d[v] - 2 * d[self.lca(u, v)]] for u, v in queries]
