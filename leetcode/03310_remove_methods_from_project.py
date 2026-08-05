class Solution:
    def remainingMethods(
        self, n: int, k: int, invocations: List[List[int]]
    ) -> List[int]:
        adj = [[] for _ in range(n)]
        for u, v in invocations:
            adj[u].append(v)

        sus = [False] * n
        sus[k] = True

        q = deque([k])
        while q:
            for v in adj[q.popleft()]:
                if not sus[v]:
                    sus[v] = True
                    q.append(v)

        for u, v in invocations:
            if not sus[u] and sus[v]:
                return list(range(n))

        return [u for u in range(n) if not sus[u]]
