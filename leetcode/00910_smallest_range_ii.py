class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = nums[-1] - nums[0]
        last = nums[-1] - k
        first = nums[0] + k
        for a, b in pairwise(nums):
            high = last if last >= a + k else a + k
            low = first if first <= b - k else b - k
            ans = ans if ans <= high - low else high - low
        return ans
