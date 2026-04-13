class Solution:
    def getSmallestString(self, s: str) -> str:
        digits = list(s)
        for i, (a, b) in enumerate(pairwise(digits)):
            if a > b and (ord(a) - ord(b)) % 2 == 0:
                digits[i], digits[i + 1] = digits[i + 1], digits[i]
                break
        return "".join(digits)
