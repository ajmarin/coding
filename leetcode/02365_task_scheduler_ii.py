class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        last = defaultdict(int)
        day = 0
        for t in tasks:
            if last[t] > day:
                day = last[t]
            day += 1
            last[t] = day + space
        return day
