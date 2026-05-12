class Solution:
    def arrayChange(self, nums: List[int], operations: List[List[int]]) -> List[int]:
        idx = {}
        for i, n in enumerate(nums):
            idx[n] = i
        for u, v in operations:
            idx[v] = index = idx.pop(u)
            nums[index] = v
        return nums
