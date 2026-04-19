class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        rows, cols = len(board), len(board[0])
        for r in range(rows):
            for c in range(cols):
                count = sum(
                    board[nr][nc] & 1
                    for nr in range(max(r - 1, 0), min(r + 2, rows))
                    for nc in range(max(c - 1, 0), min(c + 2, cols))
                )
                if count == 3 or count - board[r][c] == 3:
                    board[r][c] |= 2
        for r in range(rows):
            for c in range(cols):
                board[r][c] >>= 1
