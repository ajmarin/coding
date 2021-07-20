class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        start, end = -1, -1
        poisoned = 0
        for t in timeSeries:
            if t >= end:
                poisoned += end - start
                start = t
            end = t + duration
        if end != -1:
            poisoned += end - start
        return poisoned
