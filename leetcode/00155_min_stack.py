import collections
class MinStack:

    def __init__(self):
        self.stack = collections.deque()
        

    def push(self, x: int) -> None:
        new_min = x
        if self.stack:
            new_min = min(x, self.stack[-1][1])
        self.stack.append((x, new_min))
        

    def pop(self) -> None:
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1][0]
        

    def getMin(self) -> int:
        return self.stack[-1][1]