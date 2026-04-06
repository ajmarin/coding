class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        return sum(num for num, cnt in Counter(nums).items() if cnt == 1)
