class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        land = min(s + d for s, d in zip(landStartTime, landDuration))
        water = min(s + d for s, d in zip(waterStartTime, waterDuration))
        landWater = min(max(s, land) + d for s, d in zip(waterStartTime, waterDuration))
        waterLand = min(max(s, water) + d for s, d in zip(landStartTime, landDuration))
        return min(landWater, waterLand)
