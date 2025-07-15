ORDA = ord('A')

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        val = 0
        for c in columnTitle:
            val = 26 * val + ord(c) - ORDA + 1
        return val

