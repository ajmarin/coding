class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        i, j = click
        if board[i][j] == 'M':
            board[i][j] = 'X'
            return board
        rows, cols = len(board), len(board[0])
        di_dj = [(di, dj) for di in (-1, 0, 1) for dj in (-1, 0, 1) if di or dj]
        q = collections.deque([(i, j)])
        board[i][j] = 'B'
        while q:
            i, j = q.pop()
            mine_count = sum(
                board[i + di][j + dj] == 'M' for di, dj in di_dj
                if 0 <= i + di < rows and 0 <= j + dj < cols
            )
            if mine_count:
                board[i][j] = chr(mine_count + ord('0'))
                continue
            for di, dj in di_dj:
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= rows or nj < 0 or nj >= cols or board[ni][nj] != 'E':
                    continue
                board[ni][nj] = 'B'
                q.append((ni, nj))
        return board