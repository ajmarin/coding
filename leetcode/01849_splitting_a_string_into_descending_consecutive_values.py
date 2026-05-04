class Solution:
    def splitString(self, s: str) -> bool:
        n = len(s)

        @cache
        def bt(at, curr, prev) -> bool:
            if at == n:
                return curr == -1
            curr = (10 * curr if curr != -1 else 0) + int(s[at])
            if curr > prev:
                return False
            return (curr == prev - 1 and bt(at + 1, -1, curr)) or bt(at + 1, curr, prev)

        return any(bt(i, 0, int(s[:i])) for i in range(1, n))
