class Solution:
    def __init__(self):
        self.memo = {}

    def isMatch(self, s: str, p: str) -> bool:
        memo = self.memo.get((s, p))
        if memo is not None:
            return memo
        index = 0
        ls, lp = len(s), len(p)
        for i in range(lp):
            if p[i] == '*':
                continue
            star = i + 1 < lp and p[i + 1] == '*'
            if star:
                if index < ls and p[i] != '.' and p[i] != s[index]:
                    continue
                elif self.isMatch(s[index:], p[i+2:]):
                    self.memo[(s, p)] = True
                    return True
                while index < ls and (p[i] == '.' or p[i] == s[index]):
                    index += 1
                    if self.isMatch(s[index:], p[i+2:]):
                        self.memo[(s, p)] = True
                        return True
            elif index < ls and (p[i] == '.' or p[i] == s[index]):
                index += 1
            else:
                index = -1
                break
        self.memo[(s, p)] = index == ls
        return index == ls