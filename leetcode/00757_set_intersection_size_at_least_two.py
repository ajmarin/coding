class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        index = 0
        for (start, end) in intervals:
            while index and intervals[index - 1][1] >= end:
                index -= 1
            if index and start == intervals[index - 1][0]:
                continue
            intervals[index] = start, end
            index += 1
        ans, second, largest = 0, -2, -1
        for start, end in intervals[:index]:
            largest_in = start <= largest
            second_in = start <= second
            if largest_in and second_in:
                continue
            ans += 2 - largest_in
            second = largest if largest_in else end - 1
            largest = end
        return ans