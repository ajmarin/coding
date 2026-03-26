class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        s = set(nums)
        return [n for n in range(1, len(nums) + 1) if n not in s]
