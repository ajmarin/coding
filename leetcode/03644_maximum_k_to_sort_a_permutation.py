class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        ans = -1
        for i, n in enumerate(nums):
            if n != i:
                ans &= n
        return ans if ans != -1 else 0
