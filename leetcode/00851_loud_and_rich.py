class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        deg = [0] * n
        adj = defaultdict(list)
        for a, b in richer:
            deg[b] += 1
            adj[a].append(b)

        answer = list(range(n))
        q = deque([i for i in range(n) if not deg[i]])
        while q:
            u = q.popleft()
            for v in adj[u]:
                if quiet[answer[v]] > quiet[answer[u]]:
                    answer[v] = answer[u]
                deg[v] -= 1
                if not deg[v]:
                    q.append(v)
        return answer
