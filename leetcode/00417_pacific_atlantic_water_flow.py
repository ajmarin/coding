MOVES = ((1, 0), (-1, 0), (0, 1), (0, -1))


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])
        atlantic, pacific = set(), set()

        def dfs(x, y, viz):
            if (x, y) in viz:
                return
            curr_height = heights[x][y]
            viz.add((x, y))
            for dx, dy in MOVES:
                nx = x + dx
                if dx and (nx < 0 or nx >= rows):
                    continue
                ny = y + dy
                if dy and (ny < 0 or ny >= cols):
                    continue
                if curr_height > heights[nx][ny]:
                    continue
                dfs(nx, ny, viz)

        for r in range(rows):
            dfs(r, 0, pacific)
            dfs(r, cols - 1, atlantic)
        for c in range(cols):
            dfs(0, c, pacific)
            dfs(rows - 1, c, atlantic)

        return list(map(list, atlantic & pacific))
