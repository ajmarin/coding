class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        cost = { startGene: 0 }

        def is_mutation(a: str, b: str) -> bool:
            return sum(1 for c1, c2 in zip(a, b) if c1 != c2) == 1

        q = deque([startGene])
        while q and endGene not in cost:
            curr = q.popleft()
            new_cost = cost[curr] + 1
            for other in bank:
                if other not in cost and is_mutation(curr, other):
                    cost[other] = new_cost
                    q.append(other)
        return cost[endGene] if endGene in cost else -1

