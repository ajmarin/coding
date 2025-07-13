class Solution:
    def processStr(self, s: str) -> str:
        r = ""
        for c in s:
            match c:
                case '*': r = r[:-1]
                case '#': r += r
                case '%': r = r[::-1]
                case _: r += c
        return r

