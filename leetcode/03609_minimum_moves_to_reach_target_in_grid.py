iclass Solution:
    def minMoves(self, sx: int, sy: int, tx: int, ty: int) -> int:
        cost = {(tx, ty): 0}
        q = deque(cost.keys())

        def try_append(x, y, c):
            if x < sx or y < sy or (x, y) in cost:
                return
            cost[x, y] = c
            q.append((x, y))

        while q:
            x, y = q.popleft()
            c = cost[x, y] + 1
            if x >= 2 * y:
                if not x & 1: try_append(x >> 1, y, c)
                continue
            elif y >= 2 * x:
                if not y & 1: try_append(x, y >> 1, c)
                continue
            if x > y:
                try_append(x - y, y, c)
            elif y > x:
                try_append(x, y - x, c)
            else:
                try_append(0, y, c)
                try_append(x, 0, c)

        return cost[sx, sy] if (sx, sy) in cost else -1

