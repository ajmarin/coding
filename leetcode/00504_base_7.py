class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        signal = ""
        if num < 0:
            num = -num
            signal = "-"
        digits = []
        while num:
            digits.append(str(num % 7))
            num //= 7
        return signal + "".join(reversed(digits))
