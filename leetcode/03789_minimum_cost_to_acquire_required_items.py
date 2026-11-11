class Solution:
    def minimumCost(
        self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int
    ) -> int:
        if costBoth >= cost1 + cost2:
            return cost1 * need1 + cost2 * need2
        both = min(need1, need2)
        return (
            both * costBoth
            + (need1 - both) * min(costBoth, cost1)
            + (need2 - both) * min(costBoth, cost2)
        )
