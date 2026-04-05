class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda t: -t[1])
        ans = 0
        for count, units in boxTypes:
            use = count if count < truckSize else truckSize
            ans += use * units
            truckSize -= use
            if truckSize == 0:
                break
        return ans
