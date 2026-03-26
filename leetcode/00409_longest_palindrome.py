class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = has_odd = 0
        for n in Counter(s).values():
            is_odd = n & 1
            ans += n - is_odd
            has_odd |= is_odd
        return ans + has_odd
