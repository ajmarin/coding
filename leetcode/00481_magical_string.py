class Solution:
    def magicalString(self, n: int) -> int:
        s = [1, 2, 2]
        pos = 2
        ans = curr = 1
        while len(s) < n:
            if curr == 1:
                ans += s[pos]
            s += [curr] * s[pos]
            pos += 1
            curr = 3 - curr
        return ans - (len(s) > n and s[-1] == 1)
