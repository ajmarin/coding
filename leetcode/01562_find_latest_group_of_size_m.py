class Solution:
    def findLatestStep(self, arr: List[int], m: int) -> int:
        n = len(arr) + 2
        last = {}
        parent = list(range(n))
        rank = [0] * n

        def find(a):
            if parent[a] == a:
                return a
            ret = parent[a] = find(parent[a])
            return ret

        def union(a, b):
            pa, pb = find(a), find(b)
            rank[pa] = rank[pb] = rank[pa] + rank[pb]
            parent[pb] = pa

        for i, n in enumerate(arr, 1):
            rank[n] = 1
            if rank[n - 1]:
                last[rank[find(n - 1)]] = i - 1
                union(n - 1, n)
            if rank[n + 1]:
                last[rank[find(n + 1)]] = i - 1
                union(n, n + 1)
            last[rank[find(n)]] = i
        return last.get(m, -1)
