class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        i, n = 0, len(s)
        ans = 0
        while i < n:
            left = i
            while i < n and s[i] == "0":
                i += 1
            last_zero = i
            while i < n and s[i] == "1":
                i += 1
            last_one = i
            ans = max(ans, min(last_one - last_zero, last_zero - left))
        return 2 * ans
