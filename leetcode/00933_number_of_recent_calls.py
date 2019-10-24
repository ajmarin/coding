class RecentCounter:
    def __init__(self):
        self.pings = collections.deque()

    def ping(self, t: int) -> int:
        mint = t - 3000
        self.pings.append(t)
        while self.pings[0] < mint:
            self.pings.popleft()
        return len(self.pings)