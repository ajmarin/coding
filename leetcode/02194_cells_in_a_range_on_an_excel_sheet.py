class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        r1, r2 = int(s[1]), int(s[4])
        c1, c2 = ord(s[0]), ord(s[3])
        ans = []
        for col in range(c1, c2 + 1):
            for row in range(r1, r2 + 1):
                ans.append(f"{chr(col)}{row}")
        return ans
