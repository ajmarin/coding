class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        game = ''.join(board)
        x = sum(c == 'X' for c in game)
        o = sum(c == 'O' for c in game)
        if o > x or x - o > 1:
            return False
        row_win = (
            game[0] == game[1] == game[2] != ' ',
            game[3] == game[4] == game[5] != ' ',
            game[6] == game[7] == game[8] != ' ',
        )
        rw = sum(row_win)
        if rw > 1:
            return False
        if rw:
            winner = next(game[i * 3] for i in (0,1,2) if row_win[i])
            if winner == 'X' and x == o:
                return False
        col_win = (
            game[0] == game[3] == game[6] != ' ',
            game[1] == game[4] == game[7] != ' ',
            game[2] == game[5] == game[8] != ' ',
        )
        cw = sum(col_win)
        if cw > 1:
            return False
        if cw:
            winner = next(game[i] for i in (0,1,2) if col_win[i])
            if winner == 'X' and x == o:
                return False
        diag_win = any((
            game[0] == game[4] == game[8] != ' ',
            game[2] == game[4] == game[6] != ' ',
        ))
        return not diag_win or (x > o and game[4] == 'X')