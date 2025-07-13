class Solution:
    def processStr(self, s: str, k: int) -> str:
        size = 0
        for c in s:
            match c:
                case '*':
                    if size: size -= 1
                case '#': size *= 2
                case '%': pass
                case _: size += 1
        if k >= size:
            return '.'
        for c in s[::-1]:
            match c:
                case '#':
                    size //= 2
                    if k >= size: k -= size
                case '*': size += 1
                case '%': k = size - 1 - k
                case _:
                    size -= 1
                    if size == k: return c

