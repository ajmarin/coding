class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        rows, cols = len(grid), len(grid[0])
        k = rows * cols - k
        answer = [[0 for _ in row] for row in grid]
        for i in range(rows):
            for j in range(cols):
                pos = i * cols + j + k
                row = (pos // cols) % rows
                col = pos % cols
                answer[i][j] = grid[row][col]
        return answer