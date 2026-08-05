class Solution:
    def baseNeg2(self, n: int) -> str:
        ans = []
        while n:
            ans.append("1" if n & 1 else "0")
            n = -(n >> 1)
        return "".join(reversed(ans or ["0"]))
