class Solution:
    def palindrome(self, s: str, left: int, right: int) -> bool:
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
    
    def longestPalindrome(self, s: str) -> str:
        longest = 0
        answer = ""
        for left in range(len(s)):
            for right in range(left + longest, len(s)):
                if self.palindrome(s, left, right):
                    longest = right - left + 1
                    answer = s[left:right+1]
        return answer