class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        ans = high = 0

        pfx = []
        for x in nums:
            high = x if x > high else high
            pfx.append(gcd(x, high))
        pfx.sort()

        left, right = 0, n - 1
        while left < right:
            ans += gcd(pfx[left], pfx[right])
            left += 1
            right -= 1
        return ans
