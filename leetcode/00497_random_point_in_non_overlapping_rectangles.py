class Solution:

    def __init__(self, rects: List[List[int]]):
        n = len(rects)
        self.rects = [None] * n
        self.weights = [0] * n
        self.points = 0
        for i, (x1, y1, x2, y2) in enumerate(rects):
            width = x2 - x1 + 1
            height = y2 - y1 + 1
            self.points += width * height
            self.weights[i] = self.points
            self.rects[i] = x1, y1, width, height

    def pick(self) -> List[int]:
        index = random.randrange(0, self.points)
        left, right = 0, len(self.rects)
        while left < right:
            mid = (left + right) >> 1
            if self.weights[mid] <= index:
                left = mid + 1
            else:
                right = mid
        x1, y1, width, height = self.rects[left]
        index -= self.weights[left - 1] if left else 0
        return [x1 + (index % width), y1 + (index // width)]