class ExamRoom:
    def __init__(self, n: int):
        self.busy = []
        self.last_seat = n - 1

    def seat(self) -> int:
        busy = self.busy
        if not busy:
            busy.append(0)
            return 0

        d, pos = busy[0], 0
        for a, b in pairwise(busy):
            if (b - a) >> 1 > d:
                d = (b - a) >> 1
                pos = (b + a) >> 1
        if self.last_seat - busy[-1] > d:
            pos = self.last_seat
        insort(busy, pos)
        return pos

    def leave(self, p: int) -> None:
        self.busy.remove(p)
