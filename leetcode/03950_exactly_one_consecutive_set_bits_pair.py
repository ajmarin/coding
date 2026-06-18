class Solution:
    def consecutiveSetBits(self, n: int) -> bool:
        binn = bin(n)
        return binn.count("11") == 1 and binn.count("111") == 0
