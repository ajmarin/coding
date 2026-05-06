class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        ans = -1001
        total = sum(nums)
        c = Counter(nums)
        for n in nums:
            outlier = total - 2 * n
            if c[outlier] > (outlier == n):
                ans = outlier if outlier > ans else ans
        return ans
