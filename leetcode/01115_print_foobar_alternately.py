class FooBar:
    def __init__(self, n):
        self.n = n
        self.foos = 0
        self.bars = 0

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            while self.bars < self.foos:
                time.sleep(0.0001)
            printFoo()
            self.foos += 1

    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            while self.foos == self.bars:
                time.sleep(0.0001)
            printBar()
            self.bars += 1