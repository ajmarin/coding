class Allocator:
    def __init__(self, n: int):
        self.blocks = [(0, n)]
        self.borrowed = defaultdict(list)

    def allocate(self, size: int, mID: int) -> int:
        for i, (start, free) in enumerate(self.blocks):
            if free >= size:
                rem = free - size
                if not rem:
                    self.blocks.pop(i)
                else:
                    self.blocks[i] = (start + size, rem)
                self.borrowed[mID].append((start, size))
                return start
        return -1

    def freeBlock(self, start: int, size: int):
        end = start + size
        for i, (begin, free) in enumerate(self.blocks):
            if begin + free == start:
                if i + 1 < len(self.blocks) and self.blocks[i + 1][0] == end:
                    self.blocks[i] = (begin, free + size + self.blocks[i + 1][1])
                    self.blocks.pop(i + 1)
                else:
                    self.blocks[i] = (begin, free + size)
                return
            elif begin > end:
                self.blocks.insert(i, (start, size))
                return
            elif begin == end:
                self.blocks[i] = (start, size + free)
                return
        self.blocks.append((start, size))

    def freeMemory(self, mID: int) -> int:
        freed = 0
        for start, size in self.borrowed[mID]:
            self.freeBlock(start, size)
            freed += size
        self.borrowed[mID] = []
        return freed
