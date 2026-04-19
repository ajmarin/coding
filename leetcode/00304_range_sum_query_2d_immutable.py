class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        cols = len(matrix[0])
        prev = [0] * cols
        m = []
        for row in matrix:
            curr = []
            for p, acc in zip(prev, accumulate(row)):
                curr.append(p + acc)
            m.append(curr)
            prev = curr
        self.m = m

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        m = self.m
        return (
            m[row2][col2]
            + (m[row1 - 1][col1 - 1] if row1 and col1 else 0)
            - (m[row1 - 1][col2] if row1 else 0)
            - (m[row2][col1 - 1] if col1 else 0)
        )
