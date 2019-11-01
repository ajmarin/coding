import threading
class DiningPhilosophers:
    def __init__(self):
        self.counter = 0
        self.round = 0
        self.events = [threading.Event() for _ in range(5)]
        self.nextRound = [0, 1, 0, 1, 2]
        self.bumpLock = threading.Lock()
        self.events[0].set()

    def bumpCounter(self):
        self.bumpLock.acquire()
        self.counter += 1
        if not self.counter & 1:
            self.events[self.round].clear()
            self.round = (self.round + 1) % 5
            self.events[self.round].set()
        self.bumpLock.release()

    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        self.events[self.nextRound[philosopher]].wait()
        self.nextRound[philosopher] += 2 + (philosopher == self.round)
        self.nextRound[philosopher] %= 5
        pickLeftFork()
        pickRightFork()
        eat()
        putLeftFork()
        putRightFork()
        self.bumpCounter()