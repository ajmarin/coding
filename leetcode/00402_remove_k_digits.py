class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        s = deque()
        for n in num:
            while s and k and n < s[-1]:
                s.pop()
                k -= 1
            s.append(n)
        while k:
            s.pop()
            k -= 1
        return ''.join(s).lstrip('0') or '0'