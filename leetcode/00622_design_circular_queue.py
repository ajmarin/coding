class MyCircularQueue:
    def __init__(self, k: int):
        self.q = [None] * k
        self.front = 0
        self.rear = k - 1
        self.size = k

    def enQueue(self, value: int) -> bool:
        pos = (self.rear + 1) % self.size
        if self.q[pos] is None:
            self.rear = pos
            self.q[pos] = value
            return True
        return False

    def deQueue(self) -> bool:
        if self.q[self.front] is not None:
            self.q[self.front] = None
            self.front = (self.front + 1) % self.size
            return True
        return False

    def Front(self) -> int:
        x = self.q[self.front]
        return x if x is not None else -1

    def Rear(self) -> int:
        x = self.q[self.rear]
        return x if x is not None else -1

    def isEmpty(self) -> bool:
        return self.q[self.front] is None

    def isFull(self) -> bool:
        return (self.rear - self.front) % self.size == self.size - 1 and self.q[self.front] is not None