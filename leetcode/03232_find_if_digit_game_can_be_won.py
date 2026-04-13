class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        return sum(n for n in nums if n < 10) * 2 != sum(nums)
