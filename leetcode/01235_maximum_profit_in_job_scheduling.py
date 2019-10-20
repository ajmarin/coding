class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        count = 1
        remap = dict()
        for x in sorted(startTime + endTime):
            if x in remap:
                continue
            remap[x] = count
            count += 1
        max_profit = 0
        dp = [0] * count
        jobs = list(zip(map(remap.get, startTime), map(remap.get, endTime), profit))
        jobs.sort()
        pos = 0
        for i in range(1, count):
            dp[i] = max(dp[i], dp[i - 1])
            while pos < len(jobs) and jobs[pos][0] == i:
                _, end, profit = jobs[pos]
                dp[end] = max(dp[end], dp[i] + profit)
                pos += 1
        return dp[count - 1]