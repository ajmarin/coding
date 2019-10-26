class SnapshotArray:
    def __init__(self, length: int):
        self.vals = [collections.deque([(0, 0)]) for _ in range(length)]
        self.snaps = 0

    def set(self, index: int, val: int) -> None:
        v = self.vals[index]
        if v[-1][0] == self.snaps:
            v[-1] = (self.snaps, val)
        else:
            v.append((self.snaps, val))

    def snap(self) -> int:
        self.snaps += 1
        return self.snaps - 1

    def get(self, index: int, snap_id: int) -> int:
        v = self.vals[index]
        if not v:
            return 0
        snap_index = bisect.bisect_right(v, (snap_id + 1, ))
        return v[snap_index - 1][1]