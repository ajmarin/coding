class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        expected = set(range(1, len(matrix) + 1))
        return all(set(z) == expected for z in chain(matrix, zip(*matrix)))
