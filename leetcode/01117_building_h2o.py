from threading import Barrier, Semaphore


class H2O:
    def __init__(self):
        self.hyd = Semaphore(2)
        self.oxy = Semaphore(1)
        self.barrier = Barrier(3)

    def hydrogen(self, releaseHydrogen: "Callable[[], None]") -> None:
        with self.hyd:
            self.barrier.wait()
            releaseHydrogen()

    def oxygen(self, releaseOxygen: "Callable[[], None]") -> None:
        with self.oxy:
            self.barrier.wait()
            releaseOxygen()
