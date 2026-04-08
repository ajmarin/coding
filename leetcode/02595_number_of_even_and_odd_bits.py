class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        return [(n & 0x555555).bit_count(), (n & 0xAAAAAA).bit_count()]
