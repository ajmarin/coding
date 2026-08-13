class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        h = []
        ans = 0
        for l, r in intervals:
            if h and l > h[0]:
                heapreplace(h, r)
            else:
                heappush(h, r)
            ans = ans if ans > len(h) else len(h)
        return ans
