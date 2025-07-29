class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        vals = list(Counter(tasks).values())
        if any(v == 1 for v in vals): return -1
        return sum(math.ceil(v / 3) for v in vals)

