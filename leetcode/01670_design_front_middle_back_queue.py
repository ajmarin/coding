class FrontMiddleBackQueue:
    def __init__(self):
        self.q = deque([])

    def pushFront(self, val: int) -> None:
        self.q.appendleft(val)

    def pushMiddle(self, val: int) -> None:
        self.q.insert(len(self.q) // 2, val)

    def pushBack(self, val: int) -> None:
        self.q.append(val)

    def popFront(self) -> int:
        return self.q.popleft() if self.q else -1

    def popMiddle(self) -> int:
        if not self.q:
            return -1
        lsq = list(self.q)
        h = (len(lsq) - 1) // 2
        self.q = deque(lsq[:h] + lsq[h + 1 :])
        return lsq[h]

    def popBack(self) -> int:
        return self.q.pop() if self.q else -1
