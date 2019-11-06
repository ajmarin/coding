class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        def median(values: List[int]) -> float:
            l = len(values)
            if l & 1:
                return values[l // 2]
            return (values[l // 2] + values[l // 2 - 1]) / 2
        answer, window = [], []
        for i in range(len(nums)):
            if i >= k:
                index = bisect.bisect_left(window, nums[i - k])
                window = window[:index] + window[index + 1:]
            window.insert(bisect.bisect(window, nums[i]), nums[i])
            if len(window) == k:
                answer.append(median(window))
        return answer