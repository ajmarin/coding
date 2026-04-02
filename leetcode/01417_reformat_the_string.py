class Solution:
    def reformat(self, s: str) -> str:
        digits = [c for c in s if c.isalpha()]
        letters = [c for c in s if c.isdigit()]
        d, l = len(digits), len(letters)
        if abs(d - l) > 1:
            return ""
        ans = []
        for digit, letter in zip(digits, letters):
            ans.append(digit)
            ans.append(letter)
        if l > d:
            return letters[-1] + "".join(ans)
        if d > l:
            return "".join(ans) + digits[-1]
        return "".join(ans)
