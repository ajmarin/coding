class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        return sorted(map(lambda n: n*n, A))