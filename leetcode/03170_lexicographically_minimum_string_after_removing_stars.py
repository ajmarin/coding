class Solution:
    def clearStars(self, s: str) -> str:
        h = []
        for i, c in enumerate(s):
            if c != "*":
                heappush(h, (c, -i))
            else:
                heappop(h)
        return "".join(s[i] for i in sorted(-c[1] for c in h))
