class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 256
        for i in range(n):
            ni = nums[i]
            for j in range(i + 1, n):
                if nums[j] <= ni:
                    continue
                for k in range(j + 1, n):
                    if nums[k] < nums[j]:
                        total = ni + nums[j] + nums[k]
                        ans = total if total < ans else ans
        return -(ans == 256) | ans
