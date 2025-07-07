class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        index = bisect_left(intervals, newInterval)
        start = index
        prev = index - 1
        if prev >= 0 and intervals[prev][1] >= newInterval[0]:
            newInterval[0] = intervals[prev][0]
            newInterval[1] = max(newInterval[1], intervals[prev][1])
            start = prev
        while index < n and intervals[index][0] <= newInterval[1]:
            newInterval[1] = max(newInterval[1], intervals[index][1])
            index += 1
        return intervals[:start] + [newInterval] + intervals[index:]

