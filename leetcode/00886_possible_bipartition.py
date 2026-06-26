class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        n += 1
        adj = [[] for _ in range(n)]
        color = [0] * n

        for u, v in dislikes:
            adj[u].append(v)
            adj[v].append(u)

        for i in range(1, n):
            if color[i]:
                continue
            color[i] = 1
            q = deque([i])
            while q:
                u = q.popleft()
                wanted = -color[u]
                for v in adj[u]:
                    if not color[v]:
                        color[v] = wanted
                        q.append(v)
                    elif color[v] == color[u]:
                        return False
        return True
