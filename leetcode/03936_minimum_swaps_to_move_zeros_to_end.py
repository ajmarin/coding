class Solution:
    def minimumSwaps(self, nums: list[int]) -> int:
        z = nums.count(0)
        return 0 if not z else sum(n != 0 for n in nums[-z:])
