class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        rows, cols = len(boxGrid), len(boxGrid[0])
        ans = [["."] * rows for _ in range(cols)]
        for r, row in enumerate(boxGrid):
            stones = 0
            rotated_col = ~r
            for c, val in enumerate(row):
                if val == "#":
                    stones += 1
                elif val == "*":
                    ans[c][rotated_col] = "*"
                    while stones:
                        ans[c - stones][rotated_col] = "#"
                        stones -= 1
            while stones:
                ans[cols - stones][rotated_col] = "#"
                stones -= 1
        return ans
