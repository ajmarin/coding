class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not word:
            return True
        rows = len(board)
        if not rows:
            return False
        cols = len(board[0])
        dx_dy = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        used = set()
        def solve(row: int, col: int, widx: int) -> bool:
            if (
                row < 0 or row >= rows or
                col < 0 or col >= cols or
                board[row][col] != word[widx]
            ):
                return False
            if widx + 1 == len(word):
                return True
            for dx, dy in dx_dy:
                nrow = row + dx
                ncol = col + dy
                if (nrow, ncol) not in used:
                    used.add((nrow, ncol))
                    if solve(nrow, ncol, widx + 1):
                        return True
                    used.remove((nrow, ncol))
        for i in range(rows):
            for j in range(cols):
                used = {(i, j)}
                if solve(i, j, 0):
                    return True
        return False