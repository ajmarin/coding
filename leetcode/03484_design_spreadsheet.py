class Spreadsheet:

    def __init__(self, rows: int):
        self.mem = defaultdict(int)

    def setCell(self, cell: str, value: int) -> None:
        self.mem[cell] = value

    def resetCell(self, cell: str) -> None:
        self.mem[cell] = 0

    def getCell(self, cref: str) -> int:
        return self.mem[cref] if 'A' <= cref[0] <= 'Z' else int(cref)

    def getValue(self, formula: str) -> int:
        return sum(map(self.getCell, formula[1:].split('+')))

