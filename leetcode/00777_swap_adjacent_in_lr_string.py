class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        L = len(start)
        s, e = 0, 0
        while s < L or e < L:
            while s < L and start[s] == 'X':
                s += 1
            while e < L and end[e] == 'X':
                e += 1
            if s == L or e == L:
                break
            if start[s] == 'L' and e > s:
                return False
            if start[s] == 'R' and s > e:
                return False
            if start[s] != end[e]:
                return False
            s += 1
            e += 1
        return s == e == L