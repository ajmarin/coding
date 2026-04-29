class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        ans = [set() for _ in range(n)]
        deg = [0] * n
        adj = defaultdict(list)

        for u, v in edges:
            deg[v] += 1
            adj[u].append(v)

        q = deque([u for u in range(n) if not deg[u]])
        while q:
            u = q.popleft()
            for v in adj[u]:
                ans[v] |= ans[u]
                ans[v].add(u)
                deg[v] -= 1
                if not deg[v]:
                    q.append(v)

        return [sorted(ancestors) for ancestors in ans]
