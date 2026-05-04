class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        distinct = set(nums)
        return len(distinct | {int(str(n)[::-1]) for n in distinct})
