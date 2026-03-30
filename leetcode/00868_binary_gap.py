class Solution:
    def binaryGap(self, n: int) -> int:
        ans = pos = 0
        prev = -1
        while n:
            if n & 1:
                if prev != -1:
                    ans = max(ans, pos - prev)
                prev = pos
            n >>= 1
            pos += 1
        return ans
