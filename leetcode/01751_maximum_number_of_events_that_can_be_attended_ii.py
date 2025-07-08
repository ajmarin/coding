class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()

        n = len(events)
        dp = [[0] * (n + 1) for _ in range(k + 1)]
        for index in range(n - 1, -1, -1):
            e = events[index]
            after_index = bisect_right(events, e[1], key=itemgetter(0))
            for i in range(1, k + 1):
                dp[i][index] = max(
                    dp[i][index + 1],
                    dp[i - 1][after_index] + e[2]
                )
        return dp[k][0]

