class MapSum:
    def __init__(self):
        self.values = {}

    def insert(self, key: str, val: int) -> None:
        self.values[key] = val

    def sum(self, prefix: str) -> int:
        return sum(v for k, v in self.values.items() if k.startswith(prefix))