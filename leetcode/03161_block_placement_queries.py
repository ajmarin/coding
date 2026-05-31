class FenwickTree:
    def __init__(self, size):
        self.t = [0] * size
        self.sz = size

    def update(self, pos: int, val: int) -> None:
        tree = self.t
        while pos < self.sz:
            tree[pos] = val if val > tree[pos] else tree[pos]
            pos += pos & -pos

    def query(self, pos: int) -> int:
        tree = self.t
        res = 0
        while pos > 0:
            res = res if res > tree[pos] else tree[pos]
            pos -= pos & -pos
        return res


class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        rightmost = 1 + max(q[1] for q in queries)
        bit = FenwickTree(rightmost)
        obstacles = SortedList([0, rightmost])

        for q in queries:
            if q[0] == 1:
                obstacles.add(q[1])

        prev = 0
        for x in obstacles:
            if x:
                bit.update(x, x - prev)
            prev = x

        ans = []
        for q in reversed(queries):
            x = q[1]
            idx = obstacles.bisect_left(x)
            if q[0] == 2:
                prev = (
                    x
                    if idx < len(obstacles) and obstacles[idx] == x
                    else obstacles[idx - 1]
                )
                ans.append(max(bit.query(prev), x - prev) >= q[2])
            else:
                before, after = obstacles[idx - 1], obstacles[idx + 1]
                bit.update(after, after - before)
                obstacles.discard(x)
        return ans[::-1]
