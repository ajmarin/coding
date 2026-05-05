class DataStream:
    def __init__(self, value: int, k: int):
        self.value = value
        self.k = k
        self.count = 0

    def consec(self, num: int) -> bool:
        if num != self.value:
            self.count = 0
            return False
        self.count += 1
        return self.count >= self.k
