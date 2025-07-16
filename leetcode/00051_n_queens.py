class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [["." for _ in range(n)] for _ in range(n)]
        cols, posd, negd = set(), set(), set()
        solutions = []

        def bt(row: int):
            if row == n:
                solutions.append(["".join(line) for line in board])
                return
            for col in range(n):
                pos = row - col
                neg = row + col
                if col in cols or pos in posd or neg in negd: continue
                cols.add(col)
                posd.add(pos)
                negd.add(neg)
                board[row][col] = 'Q'
                bt(row + 1)
                board[row][col] = '.'
                cols.remove(col)
                posd.remove(pos)
                negd.remove(neg)

        bt(0)
        return solutions
