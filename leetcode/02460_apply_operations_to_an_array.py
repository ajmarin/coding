class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        ans = []
        skip = zeros = 0
        for i in range(len(nums) - 1):
            if skip:
                skip = False
                continue
            n = nums[i]
            if n == 0:
                zeros += 1
                continue
            if n == nums[i + 1]:
                ans.append(2 * n)
                zeros += 1
                skip = True
            else:
                ans.append(n)
        return ans + ([nums[-1]] if not skip else []) + [0] * zeros
