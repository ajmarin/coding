class MyCalendar:
    def __init__(self):
        self.events = []

    def book(self, startTime: int, endTime: int) -> bool:
        tup = (startTime, endTime)
        if not self.events:
            self.events.append(tup)
            return True
        i = bisect_left(self.events, tup)
        if i and self.events[i - 1][1] > startTime:
            return False
        if i < len(self.events) and self.events[i][0] < endTime:
            return False
        self.events.insert(i, tup)
        return True
