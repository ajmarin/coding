class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        pos = [None] * (n * n)
        for r, row in enumerate(grid):
            for c in range(n):
                pos[row[c]] = (r, c)
        if pos[0] != (0, 0):
            return False
        pr = pc = 0
        for r, c in pos[1:]:
            dr, dc = abs(r - pr), abs(c - pc)
            if dr > dc:
                dr, dc = dc, dr
            if dr != 1 or dc != 2:
                return False
            pr, pc = r, c
        return True
