DIRS = (0, 1, 0, -1, 0)


class Solution:
    def colorBorder(
        self, grid: List[List[int]], row: int, col: int, color: int
    ) -> List[List[int]]:
        rows, cols = len(grid), len(grid[0])
        viz = set()
        dfs_color = grid[row][col]

        to_change = []

        def dfs(r, c):
            if (r, c) in viz:
                return
            viz.add((r, c))
            is_border = False
            for dr, dc in pairwise(DIRS):
                nr, nc = r + dr, c + dc
                can_move = (
                    0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == dfs_color
                )
                is_border |= not can_move
                if can_move:
                    dfs(nr, nc)
            if is_border:
                to_change.append((r, c))

        dfs(row, col)
        for r, c in to_change:
            grid[r][c] = color
        return grid
