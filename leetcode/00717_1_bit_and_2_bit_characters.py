class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i, n = 0, len(bits) - 1
        while i < n:
            i += 1 + bits[i]
        return i == n
