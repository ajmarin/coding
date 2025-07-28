class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [inf] * 366
        dp[0] = index = 0
        travel_day = days[0]
        for i in range(1, 366):
            if i != travel_day:
                dp[i] = dp[i - 1]
                continue
            best = dp[i - 1] + costs[0]
            pass7 = dp[i - 7 if i >= 7 else 0] + costs[1]
            best = pass7 if pass7 < best else best
            pass30 = dp[i - 30 if i >= 30 else 0] + costs[2]
            dp[i] = pass30 if pass30 < best else best
            index += 1
            if index == len(days): break
            travel_day = days[index]
        return dp[days[-1]]

