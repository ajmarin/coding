class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        low = min(a, b, c)
        high = max(a, b, c)
        mid = next(x for x in (a, b, c) if x not in (low, high))
        gap = high - low
        min_moves = 0 if gap == 2 else 2 - (high - mid < 3 or mid - low < 3)
        return [min_moves, gap - 2]

