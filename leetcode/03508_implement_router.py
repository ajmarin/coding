class Router:

    def __init__(self, memoryLimit: int):
        self.max_size = memoryLimit
        self.packets = deque()
        self.pset = set()
        self.timestamps = defaultdict(deque)

    def _removeOldest(self):
        key = self.packets.popleft()
        self.pset.remove(key)
        self.timestamps[key[1]].popleft()
        return key

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        key = (source, destination, timestamp)
        if key in self.pset:
            return False
        self.pset.add(key)
        self.packets.append(key)
        self.timestamps[destination].append(timestamp)
        if len(self.packets) > self.max_size:
            self._removeOldest()
        return True

    def forwardPacket(self) -> List[int]:
        return self._removeOldest() if self.packets else []

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        times = self.timestamps[destination]
        return bisect_right(times, endTime) - bisect_left(times, startTime)

