class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        return 1 - (n != 1) / 2