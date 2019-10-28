class Solution:
    def __init__(self, w: List[int]):
        self.w = w
        for i in range(1, len(w)):
            w[i] += w[i - 1]
        self.total = w[-1]

    def pickIndex(self) -> int:
        return bisect.bisect(self.w, int(self.total * random.random()))