class Solution:
    def maxOperations(self, s: str) -> int:
        ans = ones = 0
        p = "!"
        for c in s:
            if c == "1":
                ones += 1
            elif p == "1":
                ans += ones
            p = c
        return ans
