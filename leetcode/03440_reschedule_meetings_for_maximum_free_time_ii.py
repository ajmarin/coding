class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        gaps = []
        last_end = 0
        for start, end in zip(startTime, endTime):
            gap, last_end = start - last_end, end
            gaps.append(gap)
        gaps.append(eventTime - last_end)

        max_right = [0] * len(gaps)
        for i in range(len(gaps) - 1, 0, -1):
            max_right[i - 1] = max_right[i] if gaps[i] < max_right[i] else gaps[i]

        max_free, max_left = 0, 0
        for i, (start, end, gap) in enumerate(zip(startTime, endTime, gaps)):
            gap_sum = gap + gaps[i + 1]
            max_free = gap_sum if gap_sum > max_free else max_free
            duration = end - start
            free = gap_sum + duration
            if free > max_free and (max_left >= duration or max_right[i + 1] >= duration):
                max_free = free
            max_left = gap if gap > max_left else max_left
        return max_free

