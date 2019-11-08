class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        q = collections.deque()
        fresh, minutes = 0, 0
        for i, row in enumerate(grid):
            for j, value in enumerate(row):
                if value == 1:
                    fresh += 1
                elif value == 2:
                    q.append((i, j, 0))
        while q:
            i, j, minutes = q.popleft()
            for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= rows or nj < 0 or nj >= cols:
                    continue
                if grid[ni][nj] == 1:
                    fresh -= 1
                    grid[ni][nj] = 2
                    q.append((ni, nj, minutes + 1))
        return minutes if not fresh else -1