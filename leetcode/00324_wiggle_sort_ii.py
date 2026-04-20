class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        n = len(nums)
        x = sorted(nums)
        half = (n + 1) // 2
        nums[::2], nums[1::2] = x[:half][::-1], x[half:][::-1]
