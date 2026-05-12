class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        ans = 0
        n = len(nums)
        for i in range(n):
            l = 1
            for j in range(i, n):
                l = lcm(l, nums[j])
                if l > k:
                    break
                ans += l == k
        return ans
