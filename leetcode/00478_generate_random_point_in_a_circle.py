class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.r = radius
        self.x = x_center
        self.y = y_center

    def randPoint(self) -> List[float]:
        r = self.r * math.sqrt(random.random())
        a = math.pi * 2 * random.random()
        return [self.x + r * math.cos(a), self.y + r * math.sin(a)]