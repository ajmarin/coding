class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        drop = 0
        for pct in batteryPercentages:
            drop += pct - drop > 0
        return drop
