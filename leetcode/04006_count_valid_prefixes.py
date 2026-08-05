class Solution:
    def countValidPrefixes(self, s: str) -> int:
        ans = bal = 0
        for c in s:
            bal += 1 if c == "0" else -1
            ans += abs(bal) < 2
        return ans
