class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        odd = sum(p & 1 for p in position)
        return min(odd, len(position) - odd)
