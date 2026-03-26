class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        end = len(s)
        ans, twok = "", 2 * k
        for left in range(0, end, twok):
            part = s[left : left + twok]
            ans += part[k - 1 :: -1] + part[k:]
        return ans
