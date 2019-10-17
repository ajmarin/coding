class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rseen = [0] * 9
        cseen = [0] * 9
        sseen = [0] * 9
        for i in range(9):
            for j in range(9):
                v = board[i][j]
                if v == '.':
                    continue
                ordv = 1 << (ord(v) - ord('1'))
                s = 3 * (i // 3) + (j // 3)
                if rseen[i] & ordv:
                    return False
                if cseen[j] & ordv:
                    return False
                if sseen[s] & ordv:
                    return False
                rseen[i] |= ordv
                cseen[j] |= ordv
                sseen[s] |= ordv
        return True