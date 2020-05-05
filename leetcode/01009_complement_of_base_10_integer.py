class Solution:
    def bitwiseComplement(self, N: int) -> int:
        pow2 = 2
        while pow2 <= N:
            pow2 <<= 1
        return pow2 - N - 1