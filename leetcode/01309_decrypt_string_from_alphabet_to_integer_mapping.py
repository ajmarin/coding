OFFSET = ord("a") - 1


class Solution:
    def freqAlphabets(self, s: str) -> str:
        ans, q = [], []

        for c in s:
            if c == "#":
                n = q.pop() + 10 * q.pop()
                ans.extend(q)
                q = []
                ans.append(n)
            else:
                q.append(int(c))

        return "".join(map(lambda x: chr(OFFSET + x), ans + q))
