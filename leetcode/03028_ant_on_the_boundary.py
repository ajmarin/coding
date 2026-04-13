class Solution:
    def returnToBoundaryCount(self, nums: List[int]) -> int:
        ans = total = 0
        for n in nums:
            total += n
            ans += total == 0
        return ans
