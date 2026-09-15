class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        def isPalindrome(l: int, r: int) -> bool:
            if l < 0:
                return False
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True

        ans = left_start = 0
        after = -1

        for right in range(k - 1, len(s)):
            for left in (left_start - 1, left_start):
                if left > after and isPalindrome(left, right):
                    ans += 1
                    after = right
                    break
            left_start += 1
        return ans
