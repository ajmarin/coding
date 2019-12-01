class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        grid = [[-1] * 3 for _ in range(3)]
        checkcol = lambda c: grid[0][c] == grid[1][c] == grid[2][c]
        checkrow = lambda r: grid[r][0] == grid[r][1] == grid[r][2]
        player = 0
        for row, col in moves:
            grid[row][col] = player
            if (
                checkcol(col) or
                checkrow(row) or
                (row == col and grid[0][0] == grid[1][1] == grid[2][2]) or
                (row + col == 2 and grid[2][0] == grid[1][1] == grid[0][2])
            ):
                return 'AB'[player]
            player = 1 - player
        return "Pending" if len(moves) < 9 else "Draw"