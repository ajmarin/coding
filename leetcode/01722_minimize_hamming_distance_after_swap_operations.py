class Solution:
    def minimumHammingDistance(
        self, source: List[int], target: List[int], allowedSwaps: List[List[int]]
    ) -> int:
        adj = defaultdict(set)
        for u, v in allowedSwaps:
            adj[u].add(v)
            adj[v].add(u)

        visited = [False] * len(source)

        def dfs(u: int, cnt=None) -> Counter:
            cnt = cnt or Counter()
            visited[u] = True
            cnt[source[u]] += 1
            cnt[target[u]] -= 1
            for v in adj[u]:
                if not visited[v]:
                    dfs(v, cnt)
            return cnt

        return sum(
            sum(filter(lambda x: x > 0, dfs(i).values()))
            for i in range(len(source))
            if not visited[i]
        )
