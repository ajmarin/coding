class Solution:
    def solve(self, board: List[List[str]]) -> None:
        rows, cols = len(board), len(board[0])

        def dfs(r, c):
            board[r][c] = "S"
            for dr, dc in ((0, -1), (0, 1), (-1, 0), (1, 0)):
                nr = r + dr
                if nr < 0 or nr >= rows:
                    continue
                nc = c + dc
                if nc < 0 or nc >= cols or board[nr][nc] != "O":
                    continue
                dfs(nr, nc)

        for r in range(rows):
            if board[r][0] == "O":
                dfs(r, 0)
            if board[r][cols - 1] == "O":
                dfs(r, cols - 1)
        for c in range(cols):
            if board[0][c] == "O":
                dfs(0, c)
            if board[rows - 1][c] == "O":
                dfs(rows - 1, c)
        for r in range(rows):
            for c in range(cols):
                z = board[r][c]
                if z == "O":
                    board[r][c] = "X"
                elif z == "S":
                    board[r][c] = "O"
