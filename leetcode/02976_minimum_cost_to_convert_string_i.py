INF = float("inf")
ORDA = ord('a')

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        intify = lambda s: map(lambda c: ord(c) - ORDA, s)
        lower = list(intify(string.ascii_lowercase))

        swap_cost = [[INF] * len(lower) for _ in range(len(lower))]

        for c in lower:
            swap_cost[c][c] = 0

        for u, v, c in zip(intify(original), intify(changed), cost):
            swap_cost[u][v] = c if c < swap_cost[u][v] else swap_cost[u][v]

        for k in lower:
            for i in lower:
                cost_ik = swap_cost[i][k]
                if cost_ik == INF:
                    continue
                for j, val in enumerate(swap_cost[k]):
                    cand = cost_ik + val
                    swap_cost[i][j] = cand if cand < swap_cost[i][j] else swap_cost[i][j]

        total = sum(swap_cost[s][t] for s, t in zip(*map(intify, (source, target))))
        return total if total != INF else -1

