class UndergroundSystem:
    def __init__(self):
        self.count = defaultdict(int)
        self.totalTime = defaultdict(int)
        self.checkInData = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkInData[id] = stationName, t

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        fromStation, startTime = self.checkInData.pop(id)
        key = fromStation, stationName
        self.count[key] += 1
        self.totalTime[key] += t - startTime

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = startStation, endStation
        return self.totalTime[key] / self.count[key]
