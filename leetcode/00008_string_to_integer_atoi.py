class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip(' ')
        if not s:
            return 0
        index, value = 0, 0
        sign = 1
        if s[0] == '+':
            index = 1
        if s[0] == '-':
            index = 1
            sign = -1
        print(s[index:])
        while index < len(s) and s[index].isdigit():
            value = value * 10 + int(s[index])
            index = index + 1
        value = value * sign
        value = max(min(2**31 - 1, value), -2**31)
        return value