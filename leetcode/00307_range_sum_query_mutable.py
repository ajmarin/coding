class NumArray:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.nums = nums
        self.bit = [0] * (self.n + 1)
        for i, v in enumerate(nums, 1):
            self._update(i, v)

    def _update(self, index: int, val: int) -> None:
        while index <= self.n:
            self.bit[index] += val
            index += index & -index

    def update(self, index: int, val: int) -> None:
        delta = val - self.nums[index]
        self.nums[index] = val
        self._update(index + 1, delta)

    def prefixSum(self, index: int) -> int:
        res = 0
        while index:
            res += self.bit[index]
            index -= index & -index
        return res

    def sumRange(self, left: int, right: int) -> int:
        return self.prefixSum(right + 1) - self.prefixSum(left)
