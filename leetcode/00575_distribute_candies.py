class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        half = len(candyType) >> 1
        return min(half, len(set(candyType)))
