class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0]) if grid else 0    
        visited = [[False] * cols for _ in range(rows)]
        di_dj = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def visit(i: int, j: int) -> None:
            visited[i][j] = True
            for di, dj in di_dj:
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= rows:
                    continue
                if nj < 0 or nj >= cols:
                    continue
                if visited[ni][nj] or grid[ni][nj] == '0':    
                    continue
                visit(ni, nj)
        answer = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1' and not visited[i][j]:
                    visit(i, j)
                    answer += 1
        return answer