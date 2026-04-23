class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        ordered = sorted(range(n), key=lambda i: intervals[i][0])
        ans = []
        for _, end in intervals:
            index = bisect_left(ordered, end, key=lambda i: intervals[i][0])
            ans.append(-(index == n) or ordered[index])
        return ans
