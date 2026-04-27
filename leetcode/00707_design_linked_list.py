class MyLinkedList:
    def __init__(self):
        self.q = deque()

    def get(self, index: int) -> int:
        return self.q[index] if 0 <= index < len(self.q) else -1

    def addAtHead(self, val: int) -> None:
        self.q.appendleft(val)

    def addAtTail(self, val: int) -> None:
        self.q.append(val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > len(self.q):
            return
        self.q.insert(index, val)

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= len(self.q):
            return
        as_list = list(self.q)
        self.q = deque(as_list[:index] + as_list[index + 1 :])
