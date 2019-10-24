class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        target = (1, 2, 3, 4, 5, 0)
        start = tuple(board[0] + board[1])
        if start == target:
            return 0
        q = collections.deque([(0, start)])
        n = ((1, 3), (0, 2, 4), (1, 5), (0, 4), (3, 1, 5), (4, 2))
        seen = {start}
        while len(q):
            moves, current = q.popleft()
            zero = current.index(0)
            for pos in n[zero]:
                y = list(current)
                y[pos], y[zero] = y[zero], y[pos]
                y = tuple(y)
                if y == target:
                    return moves + 1
                if y not in seen:
                    seen.add(y)
                    q.append((moves + 1, y))
        return -1