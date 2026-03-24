class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        s = ""
        while columnNumber:
            columnNumber -= 1
            s += chr(ord("A") + columnNumber % 26)
            columnNumber = columnNumber // 26
        return s[::-1]
