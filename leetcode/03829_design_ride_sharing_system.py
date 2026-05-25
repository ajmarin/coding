class RideSharingSystem:
    def __init__(self):
        self.riders = deque([])
        self.drivers = deque([])
        self.rider_waiting = [False] * 1001
        self.addDriver = self.drivers.append

    def addRider(self, riderId: int) -> None:
        self.rider_waiting[riderId] = True
        self.riders.append(riderId)

    def matchDriverWithRider(self) -> List[int]:
        while self.riders and not self.rider_waiting[self.riders[0]]:
            self.riders.popleft()
        if self.drivers and self.riders:
            return [self.drivers.popleft(), self.riders.popleft()]
        return [-1, -1]

    def cancelRider(self, riderId: int) -> None:
        self.rider_waiting[riderId] = False
