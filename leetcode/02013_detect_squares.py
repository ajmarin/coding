class DetectSquares:
    def __init__(self):
        self.by_x = defaultdict(list)
        self.by_y = defaultdict(set)
        self.c = Counter()

    def add(self, point: List[int]) -> None:
        x, y = point
        self.by_x[x].append(y)
        self.by_y[y].add(x)
        self.c[tuple(point)] += 1

    def count(self, point: List[int]) -> int:
        x, y1 = point
        res = 0
        for y2 in self.by_x[x]:
            if y2 == y1:
                continue
            side = y2 - y1
            for x2 in (x + side, x - side):
                if x2 in self.by_y[y2]:
                    res += self.c[(x2, y1)] * self.c[(x2, y2)]
        return res
