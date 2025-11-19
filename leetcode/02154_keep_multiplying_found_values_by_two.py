class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        return next(original << i for i in range(30) if original << i not in nums)
