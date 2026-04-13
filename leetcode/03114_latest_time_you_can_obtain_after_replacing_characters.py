class Solution:
    def findLatestTime(self, s: str) -> str:
        c = list(s)
        if c[0] == "?":
            if c[1] == "?":
                c[0], c[1] = "1", "1"
            elif c[1] <= "1":
                c[0] = "1"
            else:
                c[0] = "0"
        if c[1] == "?":
            c[1] = "1" if c[0] == "1" else "9"
        if c[3] == "?":
            c[3] = "5"
        if c[4] == "?":
            c[4] = "9"
        return "".join(c)
