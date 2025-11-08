class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        l = 1 << n.bit_length()
        return 0 if not n else l - 1 - self.minimumOneBitOperations(n ^ (l >> 1))
