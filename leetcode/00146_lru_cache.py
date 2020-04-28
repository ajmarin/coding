from collections import OrderedDict
class LRUCache:

    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.cap = capacity

    def get(self, key: int) -> int:
        rval = self.cache.get(key, -1)
        if rval != -1:
            self.cache.move_to_end(key)
        return rval

    def put(self, key: int, value: int) -> None:
        self.cache[key] = value
        self.cache.move_to_end(key)
        while len(self.cache) > self.cap:
            self.cache.popitem(last=False)