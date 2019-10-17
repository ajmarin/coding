class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        res = ""
        length = len(s)
        step = (numRows - 1) * 2
        for row in range(numRows):
            for base in range(row, length, step):
                res += s[base]
                if row != 0 and row != numRows - 1:
                    index = base + (numRows - row - 1) * 2
                    if index < length:
                        res += s[index]
        return res