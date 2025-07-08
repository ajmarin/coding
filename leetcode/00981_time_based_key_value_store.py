class TimeMap:
    def __init__(self):
        self.timestamps = defaultdict(list)
        self.values = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.timestamps[key].append(timestamp)
        self.values[key].append(value)

    def get(self, key: str, timestamp: int) -> str:
        timestamps = self.timestamps[key]
        if not timestamps or timestamp < timestamps[0]:
            return ""
        return self.values[key][bisect_left(timestamps, timestamp + 1) - 1]

