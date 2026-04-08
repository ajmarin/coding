class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        steps = n - 1
        time %= 2 * steps
        return time + 1 if time <= steps else n - (time - steps)
