class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        cols = len(grid[0])
        prevx, currx = [0] * cols, [0] * cols
        prevy, curry = [0] * cols, [0] * cols
        ans = 0
        for row in grid:
            x = y = 0
            for j, val in enumerate(row):
                x += prevx[j] + (val == "X")
                y += prevy[j] + (val == "Y")
                if j:
                    x -= prevx[j - 1]
                    y -= prevy[j - 1]
                currx[j], curry[j] = x, y
                if x and x == y:
                    ans += x and x == y
            prevx, currx = currx, prevx
            prevy, curry = curry, prevy
        return ans
