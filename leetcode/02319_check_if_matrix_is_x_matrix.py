class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid) - 1
        for r, row in enumerate(grid):
            for c, val in enumerate(row):
                if r == c or r == n - c:
                    if val == 0:
                        return False
                elif val != 0:
                    return False
        return True

