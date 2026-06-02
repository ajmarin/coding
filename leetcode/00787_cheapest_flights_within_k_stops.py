class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        adj = defaultdict(list)
        for u, v, price in flights:
            adj[u].append((v, price))

        h = [(0, 0, src)]
        node_depth = [n + 1] * n
        while h:
            cost, depth, u = heappop(h)
            if u == dst:
                return cost
            if depth > k or depth >= node_depth[u]:
                continue
            node_depth[u] = depth
            depth += 1
            for v, price in adj[u]:
                heappush(h, (cost + price, depth, v))
        return -1
