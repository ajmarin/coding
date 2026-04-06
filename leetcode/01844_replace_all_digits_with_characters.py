class Solution:
    def replaceDigits(self, s: str) -> str:
        ans = ""
        for i in range(1, len(s), 2):
            prev = s[i - 1]
            ans += prev + chr(ord(prev) + int(s[i]))
        return ans + (s[-1] if len(s) & 1 else "")
