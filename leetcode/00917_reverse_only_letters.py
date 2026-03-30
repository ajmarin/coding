class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        c = list(s)
        n = len(s)
        left, right = 0, n - 1
        while left < right:
            while left < n and not c[left].isalpha():
                left += 1
            while right >= 0 and not c[right].isalpha():
                right -= 1
            if left < right:
                c[left], c[right] = c[right], c[left]
            left += 1
            right -= 1
        return "".join(c)
