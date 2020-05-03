class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        x = tuple(i for i, j in enumerate(nums) if j)
        return all(x[i] - x[i - 1] > k for i in range(1, len(x)))