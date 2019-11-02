class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        increasing = (n - 1) & 1
        q = collections.deque([(n - 1, 0, 0)])
        moves = {(n - 1, 0): 0}
        victory = (0, n - 1) if n & 1 else (0, 0)
        def from_num(i: int) -> int:
            row = n - 1 - (i - 1) // n
            return row, (i - 1 if row & 1 == increasing else n - i) % n
        while q:
            row, col, depth = q.popleft()
            num = 1 + n * (n - 1 - row) + (col if row & 1 == increasing else n - 1 - col)
            for i in range(num + 1, min(num + 7, n * n + 1)):
                nrow, ncol = from_num(i)
                if board[nrow][ncol] != -1:
                    nrow, ncol = from_num(board[nrow][ncol])
                if (nrow, ncol) == victory:
                    return depth + 1
                if (nrow, ncol) not in moves:
                    moves[nrow, ncol] = depth + 1
                    q.append((nrow, ncol, depth + 1))
        return -1