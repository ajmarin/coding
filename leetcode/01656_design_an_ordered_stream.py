class OrderedStream:

    def __init__(self, n: int):
        self.chunks = {}
        self.expecting = 1

    def insert(self, idKey: int, value: str) -> List[str]:
        self.chunks[idKey] = value
        ret = []
        while self.expecting in self.chunks:
            ret.append(self.chunks[self.expecting])
            self.expecting += 1
        return ret
