class PeekingIterator:
    def __init__(self, iterator):
        self.nums = deque([])
        while iterator.hasNext():
            self.nums.append(iterator.next())

    def peek(self):
        return self.nums[0]

    def next(self):
        return self.nums.popleft()

    def hasNext(self):
        return len(self.nums) > 0
