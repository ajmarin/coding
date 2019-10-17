class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        result = []
        intervals.sort()
        a, b = None, None
        for i in range(len(intervals)):
            if a is None:
                a, b = intervals[i]
            elif a <= intervals[i][0] and intervals[i][0] <= b:
                b = max(b, intervals[i][1])
            else:
                result.append([a, b])
                a, b = intervals[i]
        if a is not None:
            result.append([a, b])
        return result