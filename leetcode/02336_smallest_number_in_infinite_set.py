class SmallestInfiniteSet:
    def __init__(self):
        self.heap = []
        self.curr = 1

    def popSmallest(self) -> int:
        if self.heap:
            ret = heappop(self.heap)
            while self.heap and self.heap[0] == ret:
                heappop(self.heap)
            return ret
        self.curr += 1
        return self.curr - 1

    def addBack(self, num: int) -> None:
        if num < self.curr:
            heappush(self.heap, num)
