class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)
        mini, maxi = min(range(n), key=nums.__getitem__), max(
            range(n), key=nums.__getitem__
        )
        right, left = max(mini, maxi), min(mini, maxi)
        return min(1 + right, n - left, 1 + left + n - right)
