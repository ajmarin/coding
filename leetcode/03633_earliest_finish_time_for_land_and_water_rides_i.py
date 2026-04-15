class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        n = len(landStartTime)
        earliestLandEnd = min(landStartTime[i] + landDuration[i] for i in range(n))
        m = len(waterStartTime)
        earliestWaterEnd = min(waterStartTime[i] + waterDuration[i] for i in range(m))
        landThenWater = min(
            max(waterStartTime[i], earliestLandEnd) + waterDuration[i] for i in range(m)
        )
        waterThenLand = min(
            max(landStartTime[i], earliestWaterEnd) + landDuration[i] for i in range(n)
        )
        return min(landThenWater, waterThenLand)
