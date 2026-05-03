class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        distance = lcm(p, q)
        laps = distance // p
        if laps & 1:
            return 2 - (distance // q & 1)
        return 0
