class Solution:
    def allCellsDistOrder(
        self, rows: int, cols: int, rCenter: int, cCenter: int
    ) -> List[List[int]]:
        cells = [*product(range(rows), range(cols))]
        cells.sort(key=lambda k: abs(rCenter - k[0]) + abs(cCenter - k[1]))
        return cells
