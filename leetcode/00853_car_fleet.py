class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        fleets = slowest = 0
        for i in sorted(range(n), key=lambda i: -position[i]):
            elapsed = (target - position[i]) / speed[i]
            if elapsed > slowest:
                slowest = elapsed
                fleets += 1
        return fleets
