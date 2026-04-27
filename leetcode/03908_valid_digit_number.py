class Solution:
    def validDigit(self, n: int, x: int) -> bool:
        return str(n).find(str(x)) > 0
