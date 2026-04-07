class Robot:
    def __init__(self, width: int, height: int):
        self.pos = 0
        self.w = width
        self.h = height
        self.loop_size = 2 * (width + height) - 4
        self.moved = False

    def step(self, num: int) -> None:
        self.pos = (self.pos + num) % self.loop_size
        self.moved = True

    def getPos(self) -> List[int]:
        pos = self.pos
        halfpoint = self.loop_size // 2
        if pos > halfpoint:
            pos -= halfpoint
        coords = [min(self.w - 1, pos), max(pos - self.w + 1, 0)]
        if self.pos <= halfpoint:
            return coords
        return [self.w - 1 - coords[0], self.h - 1 - coords[1]]

    def getDir(self) -> str:
        if self.pos == 0 and self.moved:
            return "South"
        if self.pos < self.w:
            return "East"
        if self.pos <= self.loop_size / 2:
            return "North"
        if self.pos > self.loop_size - self.h + 1:
            return "South"
        return "West"
