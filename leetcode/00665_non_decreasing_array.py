class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        mod = False
        for i, n in enumerate(nums[1:]):
            if n < nums[i]:
                if mod:
                    return False
                mod = True
                if (i < 1 or nums[i - 1] <= n):
                    nums[i] = n
                else:
                    nums[i + 1] = nums[i]
        return True

