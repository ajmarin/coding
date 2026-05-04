POWERS_OF_5 = set(5**i for i in range(10))


class Solution:
    def minimumBeautifulSubstrings(self, s: str) -> int:
        n = len(s)
        ans = [16]

        def bt(index=0, curr=0, size=0):
            if index == n:
                if not curr:
                    ans[0] = size if size < ans[0] else ans[0]
                return
            curr = (curr << 1) | (s[index] == "1")
            if curr == 0:
                return
            if curr in POWERS_OF_5:
                bt(index + 1, 0, size + 1)
            bt(index + 1, curr, size)

        bt()

        return -(ans[0] == 16) | ans[0]
