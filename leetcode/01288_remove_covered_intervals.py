class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        covered = -1
        ans = len(intervals)
        for start, end in intervals:
            ans -= end <= covered
            covered = end if end > covered else covered
        return ans
