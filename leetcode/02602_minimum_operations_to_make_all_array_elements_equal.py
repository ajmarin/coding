class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        prefix = [0] + list(accumulate(nums))
        ans = []
        for q in queries:
            i = bisect_left(nums, q)
            ans.append(prefix[-1] - 2 * prefix[i] + q * (2 * i - n))
        return ans
