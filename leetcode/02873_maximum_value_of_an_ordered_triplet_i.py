class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(n):
            ni = nums[i]
            for j in range(i + 1, n):
                sub = ni - nums[j]
                if sub < 0:
                    continue
                for k in range(j + 1, n):
                    total = sub * nums[k]
                    ans = total if total > ans else ans
        return ans
