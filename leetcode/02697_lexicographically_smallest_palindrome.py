class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        chars = list(s)
        left, right = 0, len(s) - 1
        while left < right:
            if chars[left] != chars[right]:
                chars[left] = chars[right] = min(chars[left], chars[right])
            left += 1
            right -= 1
        return "".join(chars)
