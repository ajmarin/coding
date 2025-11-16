class Solution:
    def numSub(self, s: str) -> int:
        ans = ones = 0
        for c in s + "0":
            if c == "0":
                ans += ones * (ones + 1)
                ones = 0
            else:
                ones += 1
        return (ans >> 1) % (10**9 + 7)
