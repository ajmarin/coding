class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        n = len(nums)
        children = [set()] * n
        ranks = [0] * n
        scores = [0] * n

        def dfs(u, p, rank = 0):
            ranks[u] = rank
            rank += 1
            score = nums[u]
            subtree = set(adj[u]) - {p}
            for v in adj[u]:
                if v == p: continue
                s, tree = dfs(v, u, rank)
                subtree |= tree
                score ^= s
            scores[u] = score
            children[u] = subtree
            return score, subtree

        dfs(0, -1)
        total = scores[0]

        ans = inf
        for (a, b), (c, d) in combinations(edges, 2):
            if ranks[a] < ranks[b]: a = b
            if ranks[c] < ranks[d]: c = d
            sa, sc = scores[a], scores[c]
            if a in children[c]: t = (total ^ sc, sa ^ sc, sa)
            elif c in children[a]: t = (total ^ sa, sa ^ sc, sc)
            else: t = (total ^ sa ^ sc, sa, sc)
            score = max(t) - min(t)
            ans = score if score < ans else ans
        return ans


