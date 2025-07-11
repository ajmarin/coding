class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        p += '@'
        star = oldsi = -1
        pi = si = 0
        n = len(s)
        while si < n:
            a, b = p[pi], s[si]
            if a == b or a == '?':
                si += 1
                pi += 1
            elif a == '*':
                star = pi
                pi += 1
                oldsi = si
            elif star != -1:
                pi = star + 1
                oldsi += 1
                si = oldsi
            else: return False
        return all(c == '*' for c in p[pi:-1])

