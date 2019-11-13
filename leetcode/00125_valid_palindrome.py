class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = list(map(lambda x: x.lower(), filter(lambda c: c.isalpha() or c.isdigit(), s)))
        return all(c == s[~i] for i, c in enumerate(s))