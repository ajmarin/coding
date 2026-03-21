class Solution:
    def reverseSubmatrix(
        self, grid: List[List[int]], x: int, y: int, k: int
    ) -> List[List[int]]:
        for i in range(k >> 1):
            top, bot = grid[x + i], grid[x + k - 1 - i]
            for c in range(y, y + k):
                top[c], bot[c] = bot[c], top[c]
        return grid
