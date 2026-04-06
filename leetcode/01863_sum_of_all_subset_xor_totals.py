class Solution:
    def subsetXORSum(self, nums: List[int], value=0) -> int:
        if not nums:
            return value
        return self.subsetXORSum(nums[1:], value) + self.subsetXORSum(
            nums[1:], value ^ nums[0]
        )
