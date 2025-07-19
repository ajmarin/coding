class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        last = len(online) - 1
        edges = [(u, v, c) for u, v, c in edges if online[u] and online[v]]
        adj = defaultdict(list)
        for u, v, c in edges:
            adj[u].append((v, c))

        reach = defaultdict(dict)
        reach[0][inf] = 0
        q = deque([(0, inf, 0)])
        ans = -1
        while q:
            u, min_edge, total_cost = q.popleft()
            if u == last: ans = min_edge if min_edge > ans else ans
            if total_cost > reach[u][min_edge]: continue

            for v, cost in adj[u]:
                new_cost = total_cost + cost
                if new_cost > k: continue
                new_min = cost if cost < min_edge else min_edge
                curr = reach[v].get(new_min, inf)
                if curr <= new_cost: continue
                reach[v][new_min] = new_cost
                q.append((v, new_min, new_cost))
        return ans

