class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        size = 0
        for c in S:
            if '0' <= c <= '9':
                size *= int(c)
            else:
                size += 1
        print(size)
        for c in reversed(S):
            K %= size
            if K == 0 and c.isalpha():
                return c
            if c.isdigit():
                size //= int(c)
                K %= size
            else:
                size -= 1