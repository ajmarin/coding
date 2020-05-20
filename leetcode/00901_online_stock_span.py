class StockSpanner:
    def __init__(self):
        self.stack = deque()

    def next(self, price: int) -> int:
        count = 1
        while self.stack and self.stack[-1][0] <= price:
            count += self.stack.pop()[1]
        self.stack.append((price, count))
        return count