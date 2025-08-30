ORD0 = ord('0')

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_mask = [0] * 9
        col_mask = [0] * 9
        box_mask = [0] * 9
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                if val != '.':
                    bit = 1 << (ord(val) - ORD0)
                    if row_mask[i] & bit: return False
                    row_mask[i] |= bit
                    if col_mask[j] & bit: return False
                    col_mask[j] |= bit
                    box = 3 * (i // 3) + (j // 3)
                    if box_mask[box] & bit: return False
                    box_mask[box] |= bit
        return True

