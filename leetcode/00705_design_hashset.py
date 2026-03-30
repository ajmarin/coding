MAX_LEN = 10**4


class MyHashSet:
    def __init__(self):
        self.store = [None] * MAX_LEN

    def get_container(self, val: int) -> List[int]:
        key = val % MAX_LEN
        if self.store[key] is None:
            self.store[key] = []
        return self.store[key]

    def add(self, key: int) -> None:
        values = self.get_container(key)
        if key not in values:
            values.append(key)

    def remove(self, key: int) -> None:
        values = self.get_container(key)
        if key in values:
            values.remove(key)

    def contains(self, key: int) -> bool:
        return key in self.get_container(key)
