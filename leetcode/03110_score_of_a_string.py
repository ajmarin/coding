class Solution:
    def scoreOfString(self, s: str) -> int:
        ord_prev = ord(s[0])
        ans = 0
        for c in s:
            ordc = ord(c)
            ans += abs(ordc - ord_prev)
            ord_prev = ordc
        return ans
