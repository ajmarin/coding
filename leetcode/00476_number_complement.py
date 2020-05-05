class Solution:
    def findComplement(self, num: int) -> int:
        pow2 = 2
        while pow2 <= num:
            pow2 <<= 1
        return pow2 - num - 1