class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        nums_set = set(nums)
        return sum(n + diff in nums_set and n + 2 * diff in nums_set for n in nums)
