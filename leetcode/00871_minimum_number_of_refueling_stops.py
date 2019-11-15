class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        # dp[s] -> how far we can get with s stops
        dp = [startFuel] + [0] * len(stations)
        for i, (at, gas) in enumerate(stations):
            for s in range(i, -1, -1):
                if dp[s] < at:
                    break
                dp[s + 1] = max(dp[s + 1], dp[s] + gas)
        return next((s for s, autonomy in enumerate(dp) if autonomy >= target), -1)