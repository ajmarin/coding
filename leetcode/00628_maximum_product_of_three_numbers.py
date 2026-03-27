class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()
        v1 = nums[0] * nums[1]
        v2 = nums[-2] * nums[-3]
        fn = max if nums[-1] > 0 else min
        return nums[-1] * fn(v1, v2)
