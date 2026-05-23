class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        c = Counter(s % 3 for s in stones)
        if c[0] % 2 == 0:
            return c[1] > 0 and c[2] > 0
        return abs(c[1] - c[2]) > 2
