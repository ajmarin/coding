class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans = bal = 0
        for c in s:
            if c == "(":
                bal += 1
            elif bal == 0:
                ans += 1
            else:
                bal -= 1
        return ans + bal
