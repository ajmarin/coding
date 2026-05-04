class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[:] = [r[::-1] for r in zip(*matrix)]

