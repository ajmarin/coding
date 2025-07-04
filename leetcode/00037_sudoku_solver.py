ORD1 = ord('1')
REG = lambda row, col: 3 * (row // 3) + col // 3

def count_ones(x: int):
    count = 0
    while x > 0:
        x &= (x - 1)
        count += 1
    return count

class Solution:
    def init(self):
        self.row_masks = [0] * 9
        self.col_masks = [0] * 9
        self.region_masks = [0] * 9

    def solve(self, board, remaining, index = 0):
        r, c = remaining[index]
        reg = REG(r, c)
        mask = self.row_masks[r] | self.col_masks[c] | self.region_masks[reg]

        def flip(bit: int):
            self.row_masks[r] ^= bit
            self.col_masks[c] ^= bit
            self.region_masks[reg] ^= bit

        index += 1

        for i in range(9):
            bit = 1 << i
            if bit & mask:
                continue
            flip(bit)
            if index == len(remaining) or self.solve(board, remaining, index):
                board[r][c] = chr(i + ORD1)
                return True
            flip(bit)
        return False

    def options(self, pos: Tuple[int, int]):
        row, col = pos
        reg = REG(row, col)
        mask = self.row_masks[row] | self.col_masks[col] | self.region_masks[reg]
        return 9 - count_ones(mask)

    def solveSudoku(self, board: List[List[str]]) -> None:
        self.init()

        remaining = []
        for row, cols in enumerate(board):
            for col, value in enumerate(cols):
                if value == ".":
                    remaining.append((row, col))
                    continue
                bit = 1 << (ord(value) - ORD1)
                self.row_masks[row] ^= bit
                self.col_masks[col] ^= bit
                self.region_masks[REG(row, col)] ^= bit

        remaining.sort(key=self.options)
        self.solve(board, remaining)
        return board

