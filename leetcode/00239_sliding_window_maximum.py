class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []
        window = sorted(nums[:k])
        maxes = [window[-1]]
        for i, n in enumerate(nums[k:]):
            window.remove(nums[i])
            bisect.insort(window, n)
            maxes.append(window[-1])
        return maxes