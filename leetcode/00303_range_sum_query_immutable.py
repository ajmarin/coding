class NumArray:
    def __init__(self, nums: List[int]):
        self.nums = nums
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]

    def sumRange(self, i: int, j: int) -> int:
        return self.nums[j] - (self.nums[i - 1] if i else 0)