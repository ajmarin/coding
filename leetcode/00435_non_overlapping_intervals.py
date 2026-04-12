class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=itemgetter(1))
        prev_end = intervals[0][1]
        ans = 0
        for i in intervals[1:]:
            if prev_end > i[0]:
                ans += 1
            else:
                prev_end = i[1]
        return ans
