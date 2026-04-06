class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        evens, odds = sorted(nums[::2]), sorted(nums[1::2], reverse=True)
        ans = []
        for even_odd in zip(evens, odds):
            ans.extend(even_odd)
        return ans + ([evens[-1]] if len(nums) & 1 else [])
