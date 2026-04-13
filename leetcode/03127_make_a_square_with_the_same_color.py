class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        for r in range(2):
            for c in range(2):
                chars = [grid[r][c], grid[r + 1][c], grid[r][c + 1], grid[r + 1][c + 1]]
                if chars.count("B") > 2 or chars.count("W") > 2:
                    return True
        return False
