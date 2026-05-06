class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        left, right = 0, n - 1
        while left < right and s[left] == s[right]:
            c = s[left]
            while left < right and s[left] == c:
                left += 1
            while left <= right and s[right] == c:
                right -= 1
        return max(right - left + 1, 0)
