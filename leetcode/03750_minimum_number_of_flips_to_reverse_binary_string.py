class Solution:
    def minimumFlips(self, n: int) -> int:
        bits = []
        while n:
            bits.append(n & 1)
            n >>= 1
        return sum(bits[i] ^ bits[~i] for i in range(len(bits) // 2)) << 1
