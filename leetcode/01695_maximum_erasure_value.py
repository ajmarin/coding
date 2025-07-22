class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        ans = 0
        last = defaultdict(lambda: -1)
        left = total = 0
        for i, n in enumerate(nums):
            total += n
            stop = last[n]
            while left < stop:
                total -= nums[left]
                left += 1
            ans = total if total > ans else ans
            last[n] = i + 1
        return ans

