class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            index, minval = -1, inf
            for i, n in enumerate(nums):
                if n < minval:
                    minval = n
                    index = i
            nums[index] *= multiplier
        return nums
