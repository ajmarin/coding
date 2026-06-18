class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        h = (hour % 12) * 30 + minutes / 2
        m = minutes * 6
        angle = abs(h - m)
        return min(angle, 360 - angle)
