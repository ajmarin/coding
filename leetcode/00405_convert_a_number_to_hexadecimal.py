HEX_DIGIT = "0123456789abcdef"


class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"
        if num < 0:
            num += 1 << 32

        ans = []
        while num > 0:
            ans.append(HEX_DIGIT[num % 16])
            num //= 16
        return "".join(reversed(ans))
