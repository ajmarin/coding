def to_adj(pairs, rates):
    adj = defaultdict(list)
    for (u, v), r in zip(pairs, rates):
        adj[u].append((v, r))
        adj[v].append((u, 1 / r))
    return adj


class Solution:
    def maxAmount(
        self,
        initialCurrency: str,
        pairs1: List[List[str]],
        rates1: List[float],
        pairs2: List[List[str]],
        rates2: List[float],
    ) -> float:
        amounts = defaultdict(float)
        amounts[initialCurrency] = 1.0

        def dfs(adj, u):
            have = amounts[u]
            for v, rate in adj[u]:
                cand = have * rate
                if cand > amounts[v]:
                    amounts[v] = cand
                    dfs(adj, v)

        dfs(to_adj(pairs1, rates1), initialCurrency)
        adj2 = to_adj(pairs2, rates2)
        for u in list(amounts.keys()):
            dfs(adj2, u)

        return amounts[initialCurrency]
