class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=itemgetter(1))
        ans = 0
        second, biggest = -1, -1
        for start, end in intervals:
            if biggest < start:
                second, biggest = end - 1, end
                ans += 2
            elif second < start:
                second, biggest = biggest - (biggest == end), end
                ans += 1
        return ans

