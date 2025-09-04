class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        dx = abs(x - z)
        dy = abs(y - z)
        if dx > dy: return 2
        if dy > dx: return 1
        return 0

