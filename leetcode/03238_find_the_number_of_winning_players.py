class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        counters = [Counter() for _ in range(n)]
        for player, color in pick:
            counters[player][color] += 1
        return sum(max(c.values(), default=0) > i for i, c in enumerate(counters))
