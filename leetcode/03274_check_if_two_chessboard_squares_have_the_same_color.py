COL = dict((letter, num) for num, letter in enumerate("abcdefgh"))
ROW = dict((digit, num) for num, digit in enumerate("0123456789"))


class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        key = lambda coord: (COL[coord[0]] + ROW[coord[1]]) & 1
        return key(coordinate1) == key(coordinate2)
