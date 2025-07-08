class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        last_end = 0
        gaps = []
        for s, e in zip(startTime, endTime):
            gaps.append(s - last_end)
            last_end = e
        gaps.append(eventTime - endTime[-1])
        ans = curr_sum = left = 0
        for i, g in enumerate(gaps):
            curr_sum += g
            if i > k:
                curr_sum -= gaps[left]
                left += 1
            if curr_sum > ans:
                ans = curr_sum
        return ans

