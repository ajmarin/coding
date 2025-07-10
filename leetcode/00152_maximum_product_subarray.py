class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = low = high = nums[0]
        for n in nums[1:]:
            candidates = (n, low * n, high * n)
            low = min(candidates)
            high = max(candidates)
            ans = ans if ans > high else high
        return ans

