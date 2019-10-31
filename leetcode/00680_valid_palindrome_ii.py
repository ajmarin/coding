class Solution:
    def validPalindrome(self, s: str) -> bool:
        def palindrome(l: int, r: int) -> bool:
            while l < r:
                if s[l] != s[r]:
                    return False, l
                l += 1
                r -= 1
            return True, -1
        end = len(s) - 1
        valid, idx = palindrome(0, end)
        return valid or palindrome(idx + 1, end - idx)[0] or palindrome(idx, end - idx - 1)[0]