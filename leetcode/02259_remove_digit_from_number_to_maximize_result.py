class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        n = len(number)
        for i, c in enumerate(number):
            if c == digit and i < n - 1 and c < number[i + 1]:
                return number[:i] + number[i + 1:]
        i = number.rfind(digit)
        return number[:i] + number[i + 1:]

