class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(32):
            ans = (ans << 1) | (n & 1)
            n >>= 1
            if not n:
                break
        return ans << (31 - i)
