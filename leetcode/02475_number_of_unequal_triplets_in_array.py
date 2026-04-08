class Solution:
    def unequalTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            ni = nums[i]
            for j in range(i + 1, n):
                nj = nums[j]
                if nj == ni:
                    continue
                for k in range(j + 1, n):
                    ans += ni != nums[k] != nj
        return ans
